/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12
 Create a branch named Part1
Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 
=============================================
Since you didn't do Project 3:
=============================================
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
 
 4) add 2 new UDTs that use only the types you copied above as member variables.
 
 5) Add destructors to these 2 new types that do something.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) add 2 member functions to each of these 2 new types.
       These member functions should make use of the member variables. 
       Maybe interact with their properties or call their member functions.
       The purpose is to demonstrate that you know how to use a class's member variables and member functions when it is a member of another class.
 
 7) use at least 2 instances of each of your UDTs in main. 
        add some std::cout statements in main() that use your UDT's member variables.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
If you need inspiration for what to write, take a look at previously approved student projects in the Slack Workspace channel for this project part.
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
    if(cardInfo != 0)
    {
        std::cout << "Paying Amount: " << amount;
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
        std::cout << "Flying\n";
        return true;
    }
    std::cout << "Falling\n";
    return false;
}

void Animal::loseLegs()
{
    for(int i = numLegs; i > 0; --i)
    {
        std::cout << "Lost a leg\n";
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
    return "done thinking\n";
}

void Animal::Brain::sleep()
{
    isAwake = false;
}

void Animal::Brain::grow()
{
    ++weight;
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
        std::cout << "Putting Animal to Sleep";
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

    jump +=1;


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

    std::cout << "good to go!" << std::endl;
    /*
     7) use at least 2 instances of each of your UDTs in main. 
        add some std::cout statements in main() that use your UDT's member variables.
    */

}
