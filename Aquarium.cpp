#include "Aquarium.h"
#include "behavior/Careful.h"
#include "behavior/Fearful.h"
#include "behavior/SuicideBomber.h"
#include "behavior/Gregarious.h"
#include "behavior/MultipleBehavior.h"


Aquarium::Aquarium(int width, int length) : CImgDisplay(){
	int         screenWidth = 1280; //screen_width();
    int         screenHeight = 1024; //screen_height();
	env = new Environment(width, length);
	cout << "Construct Aquarium" << endl;
	assign( *env, "Ecosystem Simulation" );

   	move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-length)/2) );
}

Aquarium::~Aquarium(){
	cout << "Destruct Aquarium" << endl;
	delete env;
}

void Aquarium::birth(){
   env->addCritter();
}

void Aquarium::clone(int id){
   Critter* copy = env->getCritterById(id)->clone();
   env->addCritter(copy);
}

void Aquarium::kill(int id){
   env->getCritterById(id)->dead();
}

void Aquarium::setBehavior(int id, string const & behavior){
   //delete env->getCritterById(id)->getBehavior();
   if(behavior.compare("c")==0){
      env->getCritterById(id)->setBehavior(new Careful());
   }
   else if(behavior.compare("f")==0){
      env->getCritterById(id)->setBehavior(new Fearful());
   }
   else if(behavior.compare("g")==0){
      env->getCritterById(id)->setBehavior(new Gregarious());
   }
   else if(behavior.compare("k")==0){
      env->getCritterById(id)->setBehavior(new SuicideBomber());
   }
   else{
      env->getCritterById(id)->setBehavior(new MultipleBehavior());
   }
   
}

void Aquarium::run(){
	cout << "running Aquarium" << endl;

   while ( ! is_closed() )
   {

      if (is_key(cimg::keyB)){

         birth(); 

      }

      if (is_key(cimg::keyK)){
         int id;
         cout << "which Critter do you want to kill? ?"<<endl;
         cin>>id;
         this->kill(id);
      }

      if (is_key(cimg::keyC)){
         int id;
         cout << "which Critter do you want to clone? ?"<<endl;
         cin>>id;
         this->clone(id);

      }

      if (is_key(cimg::keyS)){
         int id;
         std::string behavior;
         cout << "Which critter do you want to modify the behavior of?"<<endl;
         cin >> id;
         cout << "What behavior do you want to attribute to it?"<<endl;
         cin >> behavior;
         setBehavior(id,behavior);
      }



      if (is_keyESC()) {
         close();
      }

     
      env->step();
      display( *env );

      wait( 300 );

   } 
}