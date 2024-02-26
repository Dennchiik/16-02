#include <iostream>
#include <string>
using namespace std;

class Processor {
private:
    string model;
public:
    Processor(string m) : model(m) {}
    string getModel() { return model; }
};

class RAM {
private:
    int capacity;
public:
    RAM(int c) : capacity(c) {}
    int getCapacity() { return capacity; }
};

class Mouse {
private:
    string brand;
public:
    Mouse(string b) : brand(b) {}
    string getBrand() { return brand; }
};

class Webcam {
private:
    string resolution;
public:
    Webcam(string r) : resolution(r) {}
    string getResolution() { return resolution; }
};

class Printer {
private:
    string type;
public:
    Printer(string t) : type(t) {}
    string getType() { return type; }
};

class GraphicsCard {
private:
    string model;
public:
    GraphicsCard(string m) : model(m) {}
    string getModel() { return model; }
};

class Laptop {
private:
    Processor processor;
    RAM ram;
    Mouse mouse;
    Webcam webcam;
    Printer* printer;
    GraphicsCard* graphicsCard;
public:
    Laptop(Processor p, RAM r, Mouse m, Webcam w, Printer* pr, GraphicsCard* gc)
        : processor(p), ram(r), mouse(m), webcam(w), printer(pr), graphicsCard(gc) {}

    void printDetails() {
        cout << "Processor: " << processor.getModel() << endl;
        cout << "RAM: " << ram.getCapacity() << "GB" << endl;
        cout << "Mouse: " << mouse.getBrand() << endl;
        cout << "Webcam Resolution: " << webcam.getResolution() << endl;
        if (printer != nullptr)
            cout << "Printer Type: " << printer->getType() << endl;
        if (graphicsCard != nullptr)
            cout << "Graphics Card: " << graphicsCard->getModel() << endl;
    }
};

int main() {
    Processor intelCore("Intel Core i7");
    RAM samsungRAM(16);
    Mouse logitechMouse("Logitech");
    Webcam hdWebcam("1080p");
    Printer epsonPrinter("Inkjet");
    GraphicsCard nvidiaGraphicsCard("GeForce RTX 3070");

    Laptop myLaptop(intelCore, samsungRAM, logitechMouse, hdWebcam, &epsonPrinter, &nvidiaGraphicsCard);

    myLaptop.printDetails();

    return 0;
}
