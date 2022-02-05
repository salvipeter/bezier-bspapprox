set terminal png size 800,800
set output "1.png"
set title "Approx. with 1 segment (deg. 11 => deg. 7, C2)"
plot [-1:14] [-3:12] \
     "/tmp/bezier-cpts.txt" with lines title "original cpts", \
     "/tmp/bezier.txt" with lines title "original curve", \
     "/tmp/approx1-cpts.txt" with lines title "approx. cpts", \
     "/tmp/approx1.txt" with lines title "approx. curve"
set output "2.png"
set title "Approx. with 2 segments (deg. 11 => deg. 7, C2)"
plot [-1:14] [-3:12] \
     "/tmp/bezier-cpts.txt" with lines title "original cpts", \
     "/tmp/bezier.txt" with lines title "original curve", \
     "/tmp/approx2-cpts.txt" with lines title "approx. cpts", \
     "/tmp/approx2.txt" with lines title "approx. curve"
set output "3.png"
set title "Approx. with 3 segments (deg. 11 => deg. 7, C2)"
plot [-1:14] [-3:12] \
     "/tmp/bezier-cpts.txt" with lines title "original cpts", \
     "/tmp/bezier.txt" with lines title "original curve", \
     "/tmp/approx3-cpts.txt" with lines title "approx. cpts", \
     "/tmp/approx3.txt" with lines title "approx. curve"
set output "4.png"
set title "Approx. with 4 segments (deg. 11 => deg. 7, C2)"
plot [-1:14] [-3:12] \
     "/tmp/bezier-cpts.txt" with lines title "original cpts", \
     "/tmp/bezier.txt" with lines title "original curve", \
     "/tmp/approx4-cpts.txt" with lines title "approx. cpts", \
     "/tmp/approx4.txt" with lines title "approx. curve"
