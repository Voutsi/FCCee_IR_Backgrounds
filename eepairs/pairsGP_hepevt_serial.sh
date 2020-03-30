#!/bin/sh

nruns=100

let "j=0"

for i in `seq ${j} ${nruns}`
do

    ROOTDIR=/afs/cern.ch/user/v/voutsina/Work/FCCeeBKG_WrapUp/eepairs
    #echo $ROOTDIR
    cd $ROOTDIR/data${i}

    $ROOTDIR/pairsToHepevt.py --angle 0 --file $ROOTDIR/loop${i}/pairs.dat > $ROOTDIR/data${i}/pairs${i}.hepevt

    #fi

done
