#include "seeder.h"
Seeder* Seeder::instance = nullptr;

// [[Rcpp::export]]
void setseedGSL(const int s) {
    Seeder* seeder = Seeder::getInstance();
    seeder->setSeed(s);
    return;
}