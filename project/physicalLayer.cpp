#include<iostream>
#include<string>
#include<vector>
using namespace std;
class stimulator{
    public:
    int noOfDevices;
    int noOfConnection;
    int noOfHub;
    string topology;
    void dataTransfer(string sourceAddress,string destinationAddress,vector<vector<string>> &a);
    vector<string> createEnddevices(int n,int h);
    void display_endDevices_Hub(vector<string> &devicesAndHub,int n);
    void CreateConnections(int n,vector<vector<string>> &s);
    void showConnections(int n,vector<vector<string>> &devices);


};
void stimulator::CreateConnections(int n,vector<vector<string>> &s){
    for (int i = 0; i < n; i++)
    {
        vector<string> ans;
        cout<<"enter connection "<<(i+1)<<" : ";
        for (int j = 0; j < 2; j++)
        {
            string data;
            cin>>data;
            ans.push_back(data);

        }
        s.push_back(ans);
        
    }
}
vector<string> stimulator::createEnddevices(int n,int h){
    vector<string> addressArray;
    for(int i=0;i<(n+h);i++){
        int j=1;
        string address;
        if(i<n){
            cout<<"enter the device "<<(i+1)<<" address: ";
            cin>>address;
            addressArray.push_back(address);
        }
        else{
            cout<<"enter the address of hub : ";
            cin>>address;
            addressArray.push_back(address);
        }

        
    }
    
    
    return addressArray;

}
void stimulator ::display_endDevices_Hub(vector<string> &devicesAndHub,int n){
    for(int i=0;i<devicesAndHub.size();i++){
        if(i<n){
            cout<<"enddevice "<<i+1<<":";
            cout<<devicesAndHub[i]<<endl;
        }
        else{
            cout<<"Hub :"<<devicesAndHub[i]<<endl;
        }

    }
}


void stimulator::dataTransfer(string sourceAdress,string destinationAddress,vector<vector<string>>  &array){
    string data;
    for (int i = 0; i < array.size(); i++)
    { 
        if(array[i][0]==sourceAdress){
            cout<<"source device is found!!"<<endl;
            data=array[i][1];
            array[i][1]="0";
            break;
        }
        
    }
    cout<<"broadcasting............"<<endl;
     for (int i = 0; i < array.size(); i++)
    {
        
        if(array[i][0]==destinationAddress){
            cout<<"destination device is found now data will get stored!!"<<endl;
            array[i][1]=data;
        }
        
    }
    

}
void displayConnections(vector<vector<string>> &s){
    cout<<"connections in network :"<<endl;
    for (int i = 0; i < s.size(); i++)
    {
        cout<<"connection "<<i+1<<" : "<<endl;
        cout<<"(device1,device2) : ";
        for (int j = 0; j < s[i].size(); j++)
        {
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
}
void display(vector<vector<string>> &s){
    for (int i = 0; i < s.size(); i++)
    {
        cout<<"(address:data): ";
        for (int j = 0; j < s[i].size(); j++)
        {
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
}

int main(){
    int devices,hub,connections;
    string topology,sourceAddress,destinationAddress;
    cout<<"enter no. of enddevices: ";
    cin>>devices;
    cout<<"enter no.of hubs :";
    cin>>hub;
    cout<<"enter the no .of connections : ";
    cin>>connections;
    cout<<"enter the type of topology : ";
    cin>>topology;
    

    stimulator physicalLayer;

    physicalLayer.noOfDevices=devices;
    physicalLayer.noOfHub=hub;
    physicalLayer.noOfConnection=connections;
    physicalLayer.topology=topology;

    vector<string> enddevics;
    enddevics=physicalLayer.createEnddevices(devices,hub);
    vector<vector<string>> mappingConnections;
    
    physicalLayer.CreateConnections(connections,mappingConnections);

    cout<<"data transfer:"<<endl;
    cout<<"enter the source address : ";
    cin>>sourceAddress;
    cout<<"enter the destination address : ";
    cin>>destinationAddress;
    
    vector<vector<string>> address_data;
    
    for (int i = 0; i < enddevics.size(); i++)
    {
        vector<string> sec;
        for (int j = 0; j < 2; j++){
            string s;
            if(j==0){
                sec.push_back(enddevics[i]);
            }
            else{
                string data;
                cout<<"enter the data u want to pass from source device"<<enddevics[i]<<" : ";
                cin>>data;
                sec.push_back(data);
            }
            
        }
        address_data.push_back(sec);
        
        
    }
    
    display(address_data);
    physicalLayer.dataTransfer(sourceAddress,destinationAddress,address_data);
    display(address_data);

    
    physicalLayer.display_endDevices_Hub(enddevics,devices);
    displayConnections(mappingConnections);

    cout<<"physical layer completed!!"<<endl;

}