#include <string>
#include <iostream>

class Sales_data{
    friend Sales_data add(const Sales_data& s1, const Sales_data& s2);
    friend std::istream& read(std::istream& in, Sales_data& s);
    friend std::ostream& printf(std::ostream& out, const Sales_data& s);
public:
    Sales_data() = default;

    Sales_data(std::string& name):bookNo(name)
    {}
    Sales_data(std::string& name, unsigned int sold, double p):
        bookNo(name), uints_sold(sold), revenue(sold*p)
        {}
    Sales_data(std::istream& in);
    double avg_price()const {return uints_sold>0?revenue/uints_sold:0;}
    std::string isbn()const {return bookNo;}
    Sales_data combine(Sales_data& sd);
private:
    std::string bookNo;
    unsigned int uints_sold = 0;
    double revenue = 0.0;
};