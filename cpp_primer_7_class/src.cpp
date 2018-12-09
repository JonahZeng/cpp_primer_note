#include "sales.hpp"
using namespace std;

Sales_data::Sales_data(std::istream& in)
{
    read(in, *this);
}

Sales_data Sales_data::combine(Sales_data& s1)
{
    string name("");
    Sales_data out(name, 0, 0.0);
    if(this->bookNo == s1.bookNo){
        out.bookNo = this->bookNo;
        out.revenue = this->revenue + s1.revenue;
        out.uints_sold = this->uints_sold + s1.uints_sold;
    }
    return out;
}

istream& read(istream& in, Sales_data& s)
{
    double price = 0.0;
    if(in>>s.bookNo>>s.uints_sold>>price){
        s.revenue = s.uints_sold*price;
    }
    return in;
}

ostream& printf(std::ostream& out, const Sales_data& s)
{
    out<<s.bookNo<<endl;
    out<<s.uints_sold<<endl;
    out<<s.avg_price()<<endl;
    return out;
}

Sales_data add(const Sales_data& s1, const Sales_data& s2)
{
    if(s1.bookNo == s2.bookNo){
        string name = s1.bookNo;
        Sales_data out(name, s1.uints_sold+s2.uints_sold, s1.revenue+s2.revenue);
        return out;
    }
    else{
        string name("");
        return Sales_data(name, 0, 0.0);
    }
}

int main(void)
{
    return 0;
}