#define STRICT_R_HEADERS
#pragma once
#ifndef SEEDER
#define SEEDER

#include <Rcpp.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>
#include <mutex>
#include <thread>

class Seeder {
private:
  // gsl_rng *r = nullptr;
  static Seeder *instance;
  static std::mutex instanceMutex;

  static thread_local gsl_rng *r;
  // std::mutex seedMutex;
  Seeder() {}

public:
  static thread_local int currentSeed;
  // int currentSeed = -1;
  Seeder(Seeder const &) = delete;
  Seeder &operator=(Seeder const &) = delete;
  static Seeder *getInstance() {
    std::lock_guard<std::mutex> lock(instanceMutex);
    if (!instance) {
      instance = new Seeder();
    }
    return instance;
  }

  ~Seeder() {
    if (r) {
      gsl_rng_free(r);
    }
  }

  void setSeed(int seed) {
    if (seed < 0) {
      Rcpp::stop("Error: Seed must be a positive integer.");
    }
    // std::lock_guard<std::mutex> lock(seedMutex);
    if (r) {
      gsl_rng_free(r);
    }
    gsl_rng_env_setup();
    r = gsl_rng_alloc(gsl_rng_mt19937);
    gsl_rng_set(r, seed);
    // if (currentSeed != seed) {
    //     Rcpp::Rcout << "Updated GSL seed: " << currentSeed << std::endl;
    // }
    currentSeed = seed;
  }

  double get_uniform() {
    // std::lock_guard<std::mutex> lock(seedMutex);
    return gsl_rng_uniform(r);
  }

  double get_gaussian_ziggurat() {
    // std::lock_guard<std::mutex> lock(seedMutex);
    return gsl_ran_gaussian_ziggurat(r, 1.0);
  }

  double get_ran_flat() {
    // std::lock_guard<std::mutex> lock(seedMutex);
    return gsl_ran_flat(r, -1, 1);
  }

  gsl_rng *get_gsl_rng() {
    // std::lock_guard<std::mutex> lock(seedMutex);
    return r;
  }
};

#endif