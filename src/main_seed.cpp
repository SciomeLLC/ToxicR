#include "seeder.h"
static Seeder seeder;

// [[Rcpp::export]]
void setseedGSL(const int s) {
    seeder.setSeed(s);
    return;
}