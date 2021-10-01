/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
        { 
            // 2b) explicitly using 'this' inside this member function.
            std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
        }  
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;

        /*
        note: the example functions are implemented in-class, and the ctor/dtor show the curly braces on the same line as the function declaration.
        Do not do this.  Follow the instructions and coding style for the course.
        */
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}


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
