
#pragma once
#ifndef SEEDER
#define SEEDER

#include <Rcpp.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
 
class Seeder {
    private:
    gsl_rng *r;
    static Seeder *instance;
    Seeder(int seed) {
        gsl_rng_env_setup();
        r = gsl_rng_alloc(gsl_rng_mt19937);
        gsl_rng_set(r, seed);
    }

    public:
    Seeder(Seeder const&) = delete;
    Seeder& operator=(Seeder const&) = delete;
    static Seeder* getInstance(int seed=12345678) {
        if(!instance) {
            instance = new Seeder(seed);
        }
        return instance;
    }

    ~Seeder() {
        gsl_rng_free(r);
    }

    void setSeed(const int seed) {
        Rcpp::Rcout << "Setting seed: " << seed << std::endl;
        gsl_rng_set(r, seed);
        Rcpp::Rcout << "Seed set: " << seed << std::endl;
    }

    gsl_rng* get_gsl_rng() {
        return r;
    }
};
#endif