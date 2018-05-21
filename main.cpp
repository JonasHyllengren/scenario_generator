#include <random>
#include <iostream>


std::default_random_engine re;

double MAX_SCENARIO_SIZE = 1000.0;
std::uniform_real_distribution<double> random_pos(0,MAX_SCENARIO_SIZE);
double MAX_START_VELOCITY = 3.0;
std::uniform_real_distribution<double> random_vel(-MAX_START_VELOCITY,MAX_START_VELOCITY);
double PROCESS_NOISE = 1.0;
std::normal_distribution<double> process_noise(PROCESS_NOISE);

using Position = double[3];
using Velocity = double[3];


class Target{
public:
   Target() : pos{random_pos(re), random_pos(re), random_pos(re)}, 
              vel{random_vel(re), random_vel(re), random_vel(re)} {}
   void move(){
      pos[0] = pos[0] + vel[0];
      pos[1] = pos[1] + vel[1];
      pos[2] = pos[2] + vel[2];
      vel[0] = vel[0] + process_noise(re) + (500 - pos[0])/100.0;
      vel[1] = vel[1] + process_noise(re) + (500 - pos[1])/100.0;
      vel[2] = vel[2] + process_noise(re) + (500 - pos[2])/100.0;
      log();   
   }
   void log(){
      std::cout << "XYZ: " << pos[0] << " " << pos[1] << " " << pos[2] << " ";
      std::cout << "vXYZ: " << vel[0] << " " << vel[1] << " " << vel[2] << " ";
      std::cout << std::endl;
   }
   int test() {}
private:
   Position pos;
   Velocity vel;
};

class Sensor{
public:
   Sensor() : pos{random_pos(re), random_pos(re), random_pos(re)} {}

private:
   Position pos;

};





constexpr int SCENARIO_DURATION = 60;

   
int main(){
   srandom(time(NULL));

   Sensor s1;
   Sensor s2;
   Sensor s3;
   
   Target t1;
   
   for (int i = 0; i< SCENARIO_DURATION; ++i){
      t1.move();
   }
}
