#include <iostream>
#include <string>
#include "Order.h"
#include "OrderEngine.h"
#include "OrderBook.h"
Order getUserInputOrder(std::string type){
    std::string id;
    double price;
    int quantity;
    std::map<std::string, Order::OrderOperation> mapStringOrderOperation{
            {"BUY",Order::OrderOperation::BUY},
            {"SELL",Order::OrderOperation::SELL},
            {"MODIFY", Order::OrderOperation::MODIFY}};
    std::cin >>id;
    if (mapStringOrderOperation[type]==Order::OrderOperation::MODIFY){
        std::cin >> type;
    }
    std::cin >> price >> quantity;
    Order::OrderOperation ordertype = mapStringOrderOperation[type];
    return Order(id, ordertype, price, quantity); 
}

int main() {
    OrderBook orderBook;
    OrderEngine engine(&orderBook); 
    std::string type;
    std::cout << "Enter Order Type Id Price Quantity: " <<std::endl;
    while(true){
        std::cin >> type;
        if(type=="PRINT"){
            engine.printOrders();
            continue;
        }
        Order order = getUserInputOrder(type);
        if (type == "BUY"){
            engine.addBuyOrder(order);
        }else if (type == "SELL"){
            engine.addSellOrder(order);
        }else if (type =="MODIFY"){
            engine.modifyOrder(order);
        }
        engine.matchOrders();
    }

}
