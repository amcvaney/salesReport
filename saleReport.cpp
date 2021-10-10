
// Author : Abigayle McVaney
// Description: Program that will out put the total sales report from a file
//             and calculate asked functions in the program.


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


//structure
struct salesPersonRecord
{
    int SalesPersonID;
    double saleByQuarter[4];
    
    double totalSale;
};

//function
void getData(salesPersonRecord salesP[],int *a)
{
    ifstream fin;
    fin.open("sales.txt");
    if(!fin)
    {
        cout<<"file failed to open";
        return;
    }
    
    while(fin>>salesP[*a].SalesPersonID>>salesP[*a].saleByQuarter[0]
          >>salesP[*a].saleByQuarter[1]
          >>salesP[*a].saleByQuarter[2]>>salesP[*a].saleByQuarter[3])
    {
        salesP[*a].totalSale = salesP[*a].saleByQuarter[0]
        +salesP[*a].saleByQuarter[1]+salesP[*a].saleByQuarter[2]
        +salesP[*a].saleByQuarter[3];
        *a += 1;
    }
    
}


//Prototypes

void totalSalesByPerson(struct salesPersonRecord salesP [], int );
void salesByQuarter(struct salesPersonRecord [], int );
void maxSaleByPerson(struct salesPersonRecord [], int );
void maxSaleByQuarter(struct salesPersonRecord [], int );



int main() {
    
    ifstream fin;
    fin.open("sales.txt");
    
    //Variables
    salesPersonRecord salesP[20];
    int a=0; //numbers in text file
    
    //Header
    cout << "\t\t\t\t\t Bubba's Company" << endl;
    cout << "\t\t\t ----------- Annual Sales Report - 2017 -----------" <<endl;
    cout << endl;
    cout << "ID \t\t QT1 \t\t QT2 \t\t QT3 \t\t QT4 \t\t Total"<<endl;
    cout << endl;
    cout << "---------------------------------------------------------------";
    cout << "-----------------------" <<endl;
    cout << endl;
    
    //Function calls
    totalSalesByPerson(salesP, a);
    getData(salesP, &a);
    salesByQuarter(salesP, a);
    maxSaleByQuarter(salesP, a);
    maxSaleByPerson(salesP, a);
    
    cout << endl;
    cout << endl;
    
    cout << endl;
    cout << "This Report is prepared by: Abigayle McVaney" << endl;
    cout << "District Number: 40" << endl;
    cout << "Date : 12-3-2018" << endl;
    
    
    
    
    return 0;
}


//Functions...

void totalSalesByPerson(salesPersonRecord salesP[], int a)
{
    for(int i=0;i<a;i++)
    {
        cout<<left<<setw(10)<<salesP[i].SalesPersonID<<left<<setw(10)
        <<salesP[i].saleByQuarter[0]<<left<<setw(10)
        <<salesP[i].saleByQuarter[1]<<left<<setw(10)
        <<salesP[i].saleByQuarter[2]<<left<<setw(10)
        <<salesP[i].saleByQuarter[3]<<left<<setw(7)
        <<salesP[i].totalSale<<endl;
    }
}


void salesByQuarter(salesPersonRecord salesP[],int a)
{
    cout<<endl;
    double total1=0,total2=0,total3=0,total4=0;
    cout<<setw(10)<<"Total";
    for(int i=0;i<4;i++)
    {
        total1 += salesP[i].saleByQuarter[0];
        total2 += salesP[i].saleByQuarter[1];
        total3 += salesP[i].saleByQuarter[2];
        total4 += salesP[i].saleByQuarter[3];
    }
    cout<<setw(10)<<total1<<setw(10)<<total2<<setw(10)
    <<total3<<setw(10)<<total4<<endl;
}

void maxSaleByPerson(salesPersonRecord salesP[],int a)
{
    int index = 0;
    double max = salesP[0].totalSale;
    for(int i=1;i<a;i++)
        if(max<salesP[i].totalSale)
        {
            index = i;
            max = salesP[i].totalSale;
        }
cout<<endl<<endl<<"Max Sales by SalesPerson: ID = "
<<salesP[index].SalesPersonID<<",\tAmount = $"<<salesP[index].totalSale<<endl;
}

void maxSaleByQuarter(salesPersonRecord sp[],int n)
{
    double total1=0,total2=0,total3=0,total4=0;
    for(int i=0;i<4;i++)
    {
        total1 += sp[i].saleByQuarter[0];
        total2 += sp[i].saleByQuarter[1];
        total3 += sp[i].saleByQuarter[2];
        total4 += sp[i].saleByQuarter[3];
    }
    cout<<endl;
    if(total1>total2&&total1>total3&&total1>total4)
        cout<<"Max Sale by Quarter: Quarter = 1, \t Amount = $"<<total1;
    else if(total2>total1&&total2>total3&&total2>total4)
        cout<<"Max Sale by Quarter: Quarter = 2, \t Amount = $"<<total2;
    else if(total3>total1&&total3>total2&&total3>total4)
        cout<<"Max Sale by Quarter: Quarter = 3, \t Amount = $"<<total3;
    else cout<<"Max Sale by Quarter: Quarter = 4, \t Amount = $"<<total4;
    
}
