$0 !~ /^#.*/ { sum += $3 }
END { printf "math2 avg = %.2f\n", sum/(NR-1) }


