#include "headers/OrderEngine.h"

OrderEngine::OrderEngine(I_OrderBook *orderbook) : orderbook(orderbook){};
void OrderEngine::addBuyOrder(const Order &buyOrder){
            orderbook->addBuyOrder(buyOrder);
        }

void OrderEngine::addSellOrder(const Order &sellOrder){
            orderbook->addSellOrder(sellOrder);
        }
void OrderEngine::matchOrders(){
            orderbook->matchOrders();
        }
void OrderEngine::modifyOrder(std::string orderId, Order::OrderOperation modifyOrderOperation, int newPrice, int newQuantity){
            orderbook->modifyOrder(orderId, modifyOrderOperation, newPrice, newQuantity);
}
void OrderEngine::modifyOrder(const Order &modifyOrder){
            orderbook->modifyOrder(modifyOrder.getId(), modifyOrder.getType(),modifyOrder.getPrice(), modifyOrder.getQuantity());
}
void OrderEngine::printOrders(){
    orderbook->printOrders();
}

