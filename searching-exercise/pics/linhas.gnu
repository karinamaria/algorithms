set style line 1 lw 4 pt 4 lc 0
set style line 2 lw 4 pt 3 lc 0

set title 'Linear Search x Binary Search'
set key inside above
set xlabel 'Array size'
set ylabel 'Runtime (in milliseconds)'

plot 'bSearchlinear.txt' title 'Linear search' with lines, 'bSearchIterative.txt' title 'Binary search' with lines
