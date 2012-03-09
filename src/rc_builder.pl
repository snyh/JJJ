#!/usr/bin/perl
use strict;
use warnings;

exit -1  unless defined $ARGV[0];

my $file = $ARGV[0];
open (FH, $file) || die ("Could not open file");

my $size=0;
while(my $data = <FH>){
  $size += length $data;
}
close FH;

print "#include <boost/array.hpp>\n";
print "boost::array<char, $size> _RC_$file = {\n";
print `hexdump  -ve '1/1 "0x%.2x,"' $file`;
print "};";
