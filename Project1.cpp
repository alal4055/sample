#include <iostream>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

struct messageBoard
{
    string type;
    bool forsale;
    string price;
};

void Leftover(struct messageBoard array[],string wanted, int num);

int main(int argc, char* argv[])
{
    messageBoard itemArray[100];
    string line;
    int x = 0;
    int counter = 0;
    int numsold = 0;
    bool forsale;
    ifstream myfile;
    myfile.open(argv[1]);
    cout << "items sold" << "\n" << "#" << endl;;

    if (myfile.is_open())
    {
        while(getline(myfile, line)) {
            int index = line.find(",");
            string type = line.substr(0, index);
            line = line.substr(index+2);
            index = line.find(",");
            string market = line.substr(0, index);
            string price = line.substr(index+2);

            if (market == "for sale"){
                forsale = true;
            }
            else{
                forsale = false;
            }

            x++;

            messageBoard newItem = {type, forsale, price};
            itemArray[counter] = newItem;
            counter++;

            for(int i=0; i<=counter;i++)
        {

            if ((itemArray[i].type == newItem.type) && (itemArray[i].forsale != newItem.forsale))
            {
                //cout<< "matching type and wanted for sale" << endl;
                if(itemArray[i].forsale == 1)//for sale
                    {
                        if(itemArray[i].price <= newItem.price)
                        {
                            cout<< itemArray[i].type << " " << itemArray[i].price<<endl;

                            for(int j=i;j<counter;j++)
                            {
                            itemArray[j]=itemArray[j+1];
                            }
                            counter = counter -2;
                            numsold++;

                            break;
                        }
                    }

                if(itemArray[i].forsale == 0) //wanted
                {
                    if (itemArray[i].price >= newItem.price)
                        {
                            cout << newItem.type<< " " << newItem.price<<endl;
                            for(int j=i;j<counter;j++)
                            {
                            itemArray[j]=itemArray[j+1];

                            }
                            counter = counter -2;
                            numsold++;
                            break;
                        }
                }

            }
        }

        }
    }
    myfile.close();

    cout<<"Items remaining in the meessage board after reading all lines in from the file."<<endl;
    cout<<"#"<<endl;
    Leftover(itemArray,"wanted", counter);
    Leftover(itemArray,"for sale", counter);

    return 0;
}
void Leftover(struct messageBoard array[],string wanted, int num)
    {
        int i;

        if (wanted == "for sale")
            for(i=0; i< num; i++)
            {
                if(array[i].forsale == 0)
                    cout<< array[i].type << ", " << "for sale" <<", " <<  array[i].price <<endl;
            }
            else
                for(int i=0; i< num; i++)
                {
                    if(array[i].forsale == 1)
                        cout<< array[i].type <<", " << "wanted" <<", "<< array[i].price <<endl;

                }
    }
