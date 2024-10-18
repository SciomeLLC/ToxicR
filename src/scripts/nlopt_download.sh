#! /bin/sh

RSCRIPT_BIN=$1

# Uncompress NLOPT source
${RSCRIPT_BIN} -e "utils::untar(tarfile = 'nlopt-src.tar.gz')"
mv nlopt-2.8.0 nlopt-src
