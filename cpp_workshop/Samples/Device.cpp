//Question 13 2018 moed bet 
//with some mods

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Device{
    protected: 
        string PrinterName;
        int pageCount = 0;
    public:
        Device(string n, int c): PrinterName(n), pageCount(c){}
        virtual bool job(int) = 0; //pure virtual function

        string getPrinterName() const{
            return PrinterName;
        }

        int getPageCount() const{
            return pageCount;
        }

        void setPageCount(int c){
            pageCount = c;
        }

       void setName(string n){
            PrinterName = n;
        }
};

class Scanner: public Device{
    protected:
        string email = "email@email.com";
    public:
        Scanner(string n, string mail = "email@email.com"): Device(n, 0){
            email = mail;
        }
        bool job(int pages) override{
            if(pages > 100000){
                return false; //too many pages
            }
            if(pages > 0){
                setPageCount(pages + getPageCount());
            }
            cout << PrinterName << ": " << "Scanning " << pageCount << " pages" << endl;
            return true;
        }
};

class Printer: public Device{
    protected:
        int paperDrawer= 100;

    public:
        Printer(string n, int p = 100): Device(n, 0){
            paperDrawer = p;
        }
        bool job(int pages) override{
            if(pages > paperDrawer){
                return false; //not enough paper
            }
            else{
                setPageCount(pages + getPageCount());
                cout << PrinterName << ": " << "Printing " << pageCount << " pages" << endl;
                return true;
            }
        }
};

bool printBatchJob(vector<Device*> &devices, int pages){
    bool success = true;
    for(int i = 0; i < devices.size(); i++){
        if(devices[i]->getPrinterName().substr(0,7) == "Printer"){     //check if the device is a printer

            if(devices[i]->getPageCount() < pages){
                cout << "Error: " << devices[i]->getPrinterName() << "only has " <<  devices[i]->getPageCount() << "pages" << endl;
                success = false;
            }
            else{
                success =  devices[i]->job(pages);
            }
        }
       
    }
   
    return success;
}

bool scanBatchJob(vector<Device*> &devices, int pages){
    bool success = true;
    for(int i = 0; i < devices.size(); i++){
        if(devices[i]->getPrinterName().substr(0,7) == "Scanner"){     //check if the device is a printer

            if(devices[i]->getPageCount() < pages){
                cout << "Error: " << devices[i]->getPrinterName() << "only has " <<  devices[i]->getPageCount() << "pages" << endl;
                success = false;
            }
            else{
                success =  devices[i]->job(pages);
            }
        }
       
    }
   
    return success;
}
int main(){
    vector<Device*> devices = {new Printer("Printer-HP", 100), new Printer("Printer-Canon", 200), new Scanner("Scanner-Epson", "laserHand@gmail.com"), new Printer("Printer-budget", 50)};

    int pages = 99;
    cout << "Printing " << pages << "pages" << endl;
    bool worked = printBatchJob(devices, pages);
    if(worked){
        cout << "Printing successful" << endl;
    }
    else{
        cout << "Printing failed" << endl;
    }

    cout << "Scanning " << pages << "pages" << endl;
    worked = printBatchJob(devices, pages);
    if(worked){
        cout << "Scanning successful" << endl;
    }
    else{
        cout << "Scanning failed" << endl;
    }
    return 0;
}