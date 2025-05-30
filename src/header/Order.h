#ifndef _ORDER_H_
#define _ORDER_H_
#include <cstddef>
#include <iostream>
#include <map>
class Order{
    public:
        enum class OrderOperation {BUY, SELL, MODIFY};
        Order(std::string id, OrderOperation type, double price, int quantity) 
            : id(id), type(type), price(price), quantity(quantity){};
        std::string getId() const{return id;}
        OrderOperation getType() const{return type;}
        double getPrice() const {return price;}
        int getQuantity() const {return quantity;}
        void setQuantity(const int newQuantity){quantity=newQuantity;};
        void setPrice(const int newPrice){price=newPrice;};
        bool operator < (const Order &rhs) const{
            return this->price < rhs.price;
        }
        friend std::ostream &operator<<(std::ostream &os, const Order &rhs) {
            os <<" "<<rhs.id << " "<< rhs.price  << " "<< rhs.quantity;
            return os;
        }
    private:
        std::string id;
        OrderOperation type;
        double price;
        int quantity;
};
#endif 