#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
 
class Seeder {
    public:
    Seeder(int seed=12345678) {
        gsl_rng_env_setup();
        r = gsl_rng_alloc(gsl_rng_default);
        gsl_rng_set(r, seed);
    }
    ~Seeder() {
        gsl_rng_free(r);
    }
    void setSeed(const int seed) {
        gsl_rng_set(r, seed);
    }
    private:
    gsl_rng *r;
};