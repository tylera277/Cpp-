#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <vector>

#include "vector.hpp"


using namespace std;



// I cant figure out how to put this as input into
// class; just settling to this for now
const int numb_of_particles = 5000;
//const double radius = 0.5;


class ParticleSimulation{
  
private:
  double mass[numb_of_particles];
  double radius[numb_of_particles];
  
  double particle_x_pos[numb_of_particles];
  double particle_y_pos[numb_of_particles];

  double particle_x_vel[numb_of_particles];
  double particle_y_vel[numb_of_particles];

public:
  
  //ParticleSimulation();

  void initialize_radii(double, double);
  void initialize_masses(double, double);  
  void initialize_pos_and_vel_randomly(int, int, int, int);
  void update_pos(double);
  void handle_wall_collisions(int,int,int,int);
  void handle_inter_particle_collisions();

  void dump_position_data_to_external_file(string);
  void dump_velocity_data_to_external_file(string);
  void print_positions();
  void print_velocities();  
  
};

void ParticleSimulation::initialize_radii(double smallParticlesRadius, double bigParticleRadius){

  radius[0] = bigParticleRadius;
  
  for(int i=1; i<numb_of_particles; i++){
    radius[i] = smallParticlesRadius;
  }
}

void ParticleSimulation::initialize_masses(double smallParticlesMasses, double bigParticleMass){
  mass[0] = bigParticleMass;

  for(int i=1; i<numb_of_particles; i++){
    mass[i] = smallParticlesMasses;
  }
}


void ParticleSimulation::initialize_pos_and_vel_randomly(int posLower,
							 int posUpper,
							 int velLower,
							 int velUpper){
  srand((unsigned) time(0));

  for (int index = 1; index < numb_of_particles; index++) {
    particle_x_pos[index] = (rand() % posUpper) + posLower;
    particle_y_pos[index] = (rand() % posUpper) + posLower;
  }

  for (int index = 1; index < numb_of_particles; index++) {
    particle_x_vel[index] = ((rand() % (2*velUpper)) + velLower);
    particle_y_vel[index] = ((rand() % (2*velUpper)) + velLower);
  }
  
}

void ParticleSimulation::update_pos(double dt){

  for(int particle=0; particle<numb_of_particles; particle++){
    particle_x_pos[particle] += (dt * particle_x_vel[particle]);
    particle_y_pos[particle] += (dt * particle_y_vel[particle]);
  }
}

void ParticleSimulation::handle_wall_collisions(int posLower,
						int posUpper,
					        int velLower,
					        int velUpper){
  //perfectly elastic collisions w/ the wall
  
  for(int particle=0; particle<numb_of_particles; particle++){
    
    //Check x direction
    if(((particle_x_pos[particle]-radius[particle]<=posLower)) or
       ((particle_x_pos[particle]+radius[particle])>=posUpper)){
      particle_x_vel[particle] *= -1;
    
  }
    if((particle_y_pos[particle]<=posLower) or
       (particle_y_pos[particle]>=posUpper)){
      particle_y_vel[particle] *= -1;     
    }
  }
}

void ParticleSimulation::handle_inter_particle_collisions(){

  int numb_of_collisions = 0;
  for(int i=0; i<numb_of_particles; i++){
    for(int j=0; j<numb_of_particles; j++){

      //Collision conditions
      if(((particle_x_pos[i]+radius[i])>=(particle_x_pos[j]-radius[j]))and(particle_x_pos[i]<particle_x_pos[j])){
	if(((particle_y_pos[i]-radius[i])<=(particle_y_pos[j]+radius[j]))and(particle_y_pos[i]>particle_y_pos[j])){

	  double rx1 = particle_x_pos[i];
	  double rx2 = particle_x_pos[j];
	  double vx1 = particle_x_vel[i];
	  double vx2 = particle_x_vel[j];

	  double ry1 = particle_y_pos[i];
	  double ry2 = particle_y_pos[j];
	  double vy1 = particle_y_vel[i];
	  double vy2 = particle_y_vel[j];


	  vector<double> rel_pos;
	  vector<double> rel_vel;
	  
	  rel_pos.push_back(rx1-rx2);
	  rel_pos.push_back(ry1-ry2);

	  rel_vel.push_back(vx1-vx2);
	  rel_vel.push_back(vy1-vy2);
	  	  
	  double r_rel;
	  double v_rel;

	  r_rel = dot_multiply(rel_pos, rel_pos);
	  v_rel = dot_multiply(rel_pos, rel_vel);

	  double fraction = v_rel / r_rel;
	  
	  vector<double> product = scalar_multiply(fraction, rel_pos);
	  double mass_i_fraction = (2.0*mass[i]) / (mass[i] + mass[j]);
	  double mass_j_fraction = (2.0*mass[j]) / (mass[i] + mass[j]);

	  
	  vector<double> v_i = scalar_multiply(mass_i_fraction, product) ;
	  
	  vector<double> v_j = scalar_multiply(-1, product);
	  v_j = scalar_multiply(mass_j_fraction, v_j);
	  

	  particle_x_vel[i] -= v_i.at(0);
	  particle_y_vel[i] -= v_i.at(1);

	  particle_x_vel[j] -= v_j.at(0);
	  particle_y_vel[j] -= v_j.at(1);
	  
	  numb_of_collisions += 1;
	  
	}
      }

    }
  }
    
  cout << "Numb collisions: " << numb_of_collisions<<endl;
}


void ParticleSimulation::dump_position_data_to_external_file(string filename){
  
  ofstream myfile;
  myfile.open(filename, ios::app);

  cout << "Printing..." << endl;
  for(int i=0; i<numb_of_particles; i++){
    myfile << particle_x_pos[i] << "," << particle_y_pos[i] << "\n";


  }
  //myfile << "\n";


}

void ParticleSimulation::dump_velocity_data_to_external_file(string filename){
  
  ofstream myfile;
  myfile.open(filename, ios::app);

  cout << "Printing..." << endl;
  for(int i=0; i<numb_of_particles; i++){
    double total_velocity = pow((pow(particle_x_vel[i],2) + pow(particle_y_vel[i],2)),1.0/2.0);
    myfile << total_velocity << "\n";


  }


}

void ParticleSimulation::print_positions(){
  for(int i=0; i<numb_of_particles; i++){
    cout<<"X: " << particle_x_pos[i] << " Y: " << particle_y_pos[i] << endl;
  }
}

void ParticleSimulation::print_velocities(){
  for(int i=0; i<numb_of_particles; i++){
    cout<<"VX: " << particle_x_vel[i] << " VY: " << particle_y_vel[i] << endl;
  }

}





  
////////  MAIN BODY ////////
int main(){
  
  ParticleSimulation ParticleSim;

  double t = 0;
  double dt = 1;
  int tEnd = 100;
  

  //Randomize velocity between -10 and 10;
  //Randomize position between 0 and 100
  ParticleSim.initialize_pos_and_vel_randomly(0,100,-10,10);
  
  ParticleSim.initialize_radii(1.0, 5.0);
  ParticleSim.initialize_masses(0.01, 1);

  string filename1 = "particle_output.csv";
  string filename2 = "particle_final_velocity.csv";
  
  ofstream myfile;
  myfile.open(filename1, ios::trunc);
  myfile << " \n " ;
  myfile.close();

  
  while(t<tEnd){
    cout << t << endl;
    ParticleSim.update_pos(dt);

    ParticleSim.handle_wall_collisions(0,100,-10,10);

    ParticleSim.handle_inter_particle_collisions();

    ParticleSim.dump_position_data_to_external_file(filename1);

    
    
    //ParticleSim.print_positions();
    //ParticleSim.print_velocities();
      
    t += dt;
  }

  ParticleSim.dump_velocity_data_to_external_file(filename2);
}
