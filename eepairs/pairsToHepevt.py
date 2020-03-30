#! /usr/bin/env python
import sys, imp
import os
import math
from string import *
import commands
from os import listdir


# --
# -- converts the file pairs.dat created by GuineaPig
# -- into a hepevt file, to be passed to Mokka
# -- Format of hepevt :
# --      N_part
# --         1   pdg  0 0 0 0  px py pz E  m  0 0 0 0
# --
# --   ./pairsToHepevt.py --file  pairs.dat  --angle 7
# --

from optparse import OptionParser
parser = OptionParser(usage="usage: %prog [options] ")
parser.add_option("--file", dest="file", help="file name of photons.dat", metavar="FILENAME")
parser.add_option("--angle",dest="angle", help="half crossing angle in mrad",metavar="ANGLE")
parser.add_option("--directory",dest="directory",help="path to files eg FCCH",metavar="PATH")
parser.add_option("--nmax",dest="nmax", help="maximum number of particles",metavar="NMAX")
(options, args) = parser.parse_args()


#BeamEnergy = float(sys.argv[1])
#PairsDat = sys.argv[2]


def ReadOneFile(PairsDat, alpha, nmax):

   thePairs = open(PairsDat,"r")
   num_lines = len(thePairs.readlines())
   #num_lines = num_lines + 2	# add the two incoming electrons, status -1
   thePairs.close()
   thePairs = open(PairsDat,"r")
   nMax = nmax
   if nMax > 0 and num_lines > nMax :
	num_lines = nMax
   print num_lines

   fl = thePairs.readline()
   idx=0
   while len(fl)>0:
      idx=idx+1
      if idx > num_lines:
	break
      id = 11
      e=float(fl.split()[0])
      signe=1
      if e<0:
	   e=-e
	   id = -11
	   signe=-1
      px = float(fl.split()[1]) * e
      py = float(fl.split()[2]) * e
      pz = float(fl.split()[3]) * e

      #print " px py pz e ",px," ",py," ",pz," ",e
      # print "  1   ",id,"    0    0    0    0    ",px," ",py," ",pz," ",e,"  0.  0. 0. 0. 0."
      #
      # Now boost from com frame to lab frame
      ta = math.tan( alpha )
      e_prime = e * math.sqrt( 1 + ta*ta ) + px * ta
      px_prime = px * math.sqrt( 1 + ta*ta ) + e * ta
      py_prime = py
      pz_prime = pz
      print "  1   ",id,"    0    0    0    0    ",px_prime," ",py_prime," ",pz_prime," ",e_prime,"  5.11e-4  0. 0. 0. 0." 

      fl = thePairs.readline()
   thePairs.close()



if __name__ == "__main__":

   if options.file is None and options.directory is None:
	print "Error, should specify either --file or --directory"
	sys.exit(1)

   if not options.file is None and not options.directory is None:
	print "Error, shoudl specify either --file or --directory"
	sys.exit(1)


   alpha = 0.
   if not options.angle is None:
	alpha = float(options.angle) / 1000.

   nmax = -1
   if not options.nmax is None:
        nmax = int(options.nmax)

   if not options.file is None:
	ReadOneFile( options.file, alpha, nmax)

   if not options.directory is None:
	thePath = options.directory
	thedirectory = [ d for d in listdir(thePath) ]
	for d in thedirectory:
	   theFile=thePath+"/"+d+"/pairs.dat"
           #theFile=thePath+"/"+d
	   ReadOneFile( theFile, alpha, nmax )





