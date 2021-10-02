/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 you can safely ignore any warnings about exit-time-destructors.
 if you would like to suppress them, add -Wno-exit-time-destructors to the .replit file 
   with the other warning suppression flags
 */





/*
 UDT 1: CarWash
 */
#include <iostream>

struct CarWash
{
    std::string washType = "basic";
    double cost;
    int numberOfWashers;
    double discountedCost = 5.0;
    double height = 10.0;
    bool hasDiscount = false;

    CarWash(double cost_, int numberOfWashers_) 
    : cost(cost_), numberOfWashers(numberOfWashers_)
    {
    }
    ~CarWash()
    {
        std::cout << "CarWash\n";
    }

    void washCar();

    void discount();

    bool pay(int cardInfo, double amount = 0.0);

    void printDiscount();

    struct Washer
    {
        double length;
        bool isOn=false;
        char color;
        bool isClockWise;
        int numberOfSides;

        Washer(char color_, bool isClockWise_ = true, int numberOfSides_ = 4) 
        : color(color_), isClockWise(isClockWise_), numberOfSides(numberOfSides_)
        {
        }
        ~Washer()
        {
            std::cout << "Washer\n";
        }

        int graduallyAddSides(int sidesToAdd = 100);
        void toggleOnOff();
        void switchDirections();
    };
    Washer washer = Washer('g');

};

void CarWash::washCar()
{
    for(int i = 1; i < numberOfWashers + 2; ++i)
    {
        std::cout << i << " Washers used\n" << "\n";
    }
}

void CarWash::discount()
{
    hasDiscount = true;
}

//not sure where to put default arguments
bool CarWash::pay(int cardInfo, double amount)
{
    if((cardInfo != 0) && (amount == 0.0))
    {
        std::cout << "\nPaying Amount: " << amount;
        return true;
    }
    return false;
}

int CarWash::Washer::graduallyAddSides(int sidesToAdd)
{
    for(int i = numberOfSides; i < numberOfSides + sidesToAdd+1; ++i)
    {
           std::cout << i << " is the current number of sides\n";
    }
    numberOfSides += sidesToAdd;
    return numberOfSides;
}

void CarWash::Washer::toggleOnOff()
{
    isOn = !isOn;
}

void CarWash::Washer::switchDirections()
{
    isClockWise = !isClockWise;
}

void CarWash::printDiscount()
{
    std::cout << this->hasDiscount << std::endl;
}
/*
 UDT 2:
 */
struct Animal
{
    int numLegs = 2;
    int numArms = 2;
    int numEyes;
    bool canFly;
    double weight;


    Animal(int numEyes_ = 2, bool canFly_=false, double weight_ = 20.0) 
    : numEyes(numEyes_), canFly(canFly_), weight(weight_)
    {
    }

    ~Animal()
    {
        std::cout << "Animal\n";
    }

    bool tryToFly();
    void loseLegs();
    double jump(); //returns jump height
    void printCanFly();

    struct Brain
    {
        int numOfCells;
        double weight;
        int age;
        bool isAwake;
        bool isGrowing;

        Brain(int numOfCells_ = 100) : numOfCells(numOfCells_)
        {
        }

        ~Brain()
        {
            std::cout << "Brain\n";
        }
    
        std::string think(std::string subject);
        void sleep();
        void grow();
    };
    Brain animalBrain;
};

bool Animal::tryToFly()
{
    if(canFly)
    {
        std::cout << "\nFlying\n";
        return true;
    }
    std::cout << "\nFalling\n";
    return false;
}

void Animal::loseLegs()
{
    for(int i = numLegs; i > 0; --i)
    {
        std::cout << "\nLost a leg\n";
    }
}
double Animal::jump()
{
    if(canFly)
    {
        return 100.0;
    }
    else
    {
        return 4.0;
    }
}

std::string Animal::Brain::think(std::string subject)
{
    for(int i = 0; i < 100; ++i)
    {
        std::cout << subject << "\n";
    }
    return subject;
}

void Animal::Brain::sleep()
{
    isAwake = false;
}

void Animal::Brain::grow()
{
    ++weight;
}

void Animal::printCanFly()
{
    std::cout << this->canFly << std::endl;
}

/*
 UDT 3:
 */
struct Lamp
{
    bool isOn=false;
    double brightness;
    int numberOfBulbs=4;
    double hue;
    double wattage;

    void turnOn();
    void light(bool hasPower=true);
    double getPowerConsumption();
    void printBrightness();

    Lamp(double brightness_, double hue_, double wattage_)
    : brightness(brightness_), hue(hue_), wattage(wattage_)
    {
    }

    ~Lamp()
    {
        std::cout << "Lamp\n";
    }
};

void Lamp::turnOn()
{
    isOn=true;
}
void Lamp::light(bool hasPower)
{
    while(isOn)
    if(hasPower && brightness < 100)
    {
        brightness += 0.01;
    }
    else
    {
       return;
    }
}

double Lamp::getPowerConsumption()
{
    return brightness * hue * wattage;
}

void Lamp::printBrightness()
{
    std::cout << this->brightness << std::endl;
}

/*
 new UDT 4:
 */
struct GasStation
{
    Lamp lamp;
    CarWash carWash;

    GasStation(Lamp l, CarWash c) 
    : lamp(l), carWash(c)
    {}

    ~GasStation()
    {
        std::cout << "End of Life Discount\n";
        carWash.discount();
    }

    void payForPremiumWash(int cardNumber);
    void nightCarWash(int cardNumber);

    
};

void GasStation::payForPremiumWash(int cardNumber)
{
    carWash.pay(cardNumber, 1000.00 * carWash.numberOfWashers);
    
}

void GasStation::nightCarWash(int cardNumber)
{
    carWash.pay(cardNumber, 500.00 * carWash.numberOfWashers);
    lamp.turnOn();
    carWash.washCar();
}

struct PetStore
{
    Lamp lizardLamp;
    Animal animal;

    PetStore(Lamp l, Animal a)
    : lizardLamp(l), animal(a)
    {}
    ~PetStore()
    {
        std::cout << "Putting Animal to Sleep\n";
        animal.animalBrain.sleep();
    }

    void growLizard();
    void lizardEpiphany();
};

void PetStore::growLizard()
{
    lizardLamp.turnOn();
    animal.animalBrain.grow();
    ++animal.numLegs;
}

/*
 new UDT 5:
 */
void PetStore::lizardEpiphany()
{
    lizardLamp.turnOn();
    animal.animalBrain.think("aha!\n");
    animal.canFly = true;
}



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */

#include <iostream>
int main()
{
    auto petStore = PetStore(Lamp(100.0, 100.0, 20.0), Animal());
    petStore.lizardEpiphany();
    petStore.growLizard();

    auto gasStation = GasStation (Lamp(100.0, 50.0, 20.0), CarWash(5.0, 4));
    gasStation.payForPremiumWash(151);
    gasStation.nightCarWash(151);

    auto lamp = Lamp(100.0, 100.0, 20.0);
    lamp.turnOn();
    lamp.getPowerConsumption();
    lamp.light(true);

    



    //Animal tests
    auto animal = Animal();
    bool isFly = animal.tryToFly();
    isFly = !isFly;
    animal.loseLegs();
    double jump = animal.jump();
    jump += 1;


    //std::cout << "\n\nJump Height: "<< jump << std::endl;




    animal.animalBrain.think("thinking about C++");
    animal.animalBrain.grow();
    animal.animalBrain.sleep();


    auto carWash = CarWash(5.0, 4);
    carWash.pay(100500, 9.00);
    carWash.discount();
    carWash.washCar();

    

    //nested
    carWash.washer.switchDirections();
    carWash.washer.graduallyAddSides(100);
    carWash.washer.toggleOnOff();


    /*
    * PROJECT 5 PART 2
    */
    std::cout << "\n\nLamp Brightness: \n" << lamp.brightness<<std::endl;
    lamp.printBrightness();

    std::cout << "\n\nDoes Wash have Discount? \n" << carWash.hasDiscount << std::endl;
    carWash.printDiscount();

    std::cout << "\n\nCan Animal Fly? \n" << animal.canFly << std::endl;
    animal.printCanFly();

    std::cout << "good to go!" << std::endl;
    /*
     7) use at least 2 instances of each of your UDTs in main. 
        add some std::cout statements in main() that use your UDT's member variables.
    */

}
