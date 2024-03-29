#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockOnce(const vector<double>& prices) {
  // TODO - you fill in here.
  if(prices.empty()) return 0.0;

  double profit = 0.0;
  double min = prices[0];

  for(auto& p : prices){
    if(min > p){
      min = p;
    }
    else{
      profit = profit > p - min ? profit : p - min;
    }

  }

  return profit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
