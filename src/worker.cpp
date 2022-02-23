#include "worker.h"
#include "string-funcs.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>

using namespace ShapeShifterTest;

Worker::Worker() {}

int Worker::factors(int n) {
  int f = 0;
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0) {
      f++;
    }
  }
  return f;
}


void Worker::work(const std::string& filename){
  std::ifstream ifs(filename);
  std::map<int, std::vector<double> > factorList;

  for (std::string line; std::getline(ifs, line); ) {
    // std::cout << line << '\n';
    auto parts = utils::tokenize(line);
    if(parts.size() == 2){
      int n = std::atoi(parts[0].c_str());
      double e = std::atof(parts[1].c_str());
      int f = factors(n);
      auto s = factorList.find(f);
      if(s == factorList.end()){
        factorList[f] = {e};
      }else{
        factorList[f].push_back(e);
      }
      

      // std::cout << n << " " << e << " " << f << std::endl;
    }
  }

  std::vector<std::pair<double, int>> result;

  std::for_each(factorList.begin(), factorList.end(), [&result] (auto e_pair) {
    // std::cout << e_pair.first << " : ";
    double sum = 0.0;
    std::for_each(e_pair.second.begin(), e_pair.second.end(), [&sum] (auto e_list){
      // std::cout << e_list << " ";
      sum += e_list;
    } );
    result.push_back(std::pair(sum / e_pair.second.size(), e_pair.first));
    // std::cout << sum << " " << (sum / e_pair.second.size()) << std::endl;
  });

  std::sort(result.begin(), result.end(), [] (auto left, auto right) {
    return left.first > right.first; // reverse sort.
  });

  for (auto r : result) {
    std::cout << "Factor: " << r.second << " Avg Efficiency: " << r.first << "\n";
  }

}