nruns=100

let "j=0"

    ROOTDIR=/afs/cern.ch/user/v/voutsina/Work/FCCeeBKG_WrapUp/eepairs


for i in `seq ${j} ${nruns}`
do
    cd $ROOTDIR/data${i}
    INFILE=$ROOTDIR/data${i}/pairs${i}.hepevt
    echo $INFILE
    COMPACTFILE=/afs/cern.ch/work/v/voutsina/guineapig++/guinea-pig.r3238/data/PairsZ/BeamParTest/Pairs/Geometry/FCCee_o1_v04/FCCee_o1_v04.xml

    rm test_sub_sim.sh
    
    cat > test_sub_sim.sh << EOF1
#!/bin/sh
unset MARLIN_DLL
source /afs/cern.ch/work/v/voutsina/guineapig++/guinea-pig.r3238/data/PairsZ/BeamParTest/Pairs/Geometry/init_ilcsoft.sh
 ddsim --inputFiles=$INFILE  --outputFile=sim_pairs_test_${i}.slcio --compactFile=$COMPACTFILE --crossingAngleBoost 0.015 --numberOfEvents=1
mv sim_pairs_test_${i}.slcio $ROOTDIR/data${i}
EOF1

    chmod u+x test_sub_sim.sh
    
    cat > paok.sub << EOF1
    executable            =  test_sub_sim.sh
    log                   =$ROOTDIR/data${i}/logfile.log
    output                =$ROOTDIR/data${i}/STDOUT 
    error                 =$ROOTDIR/data${i}/STDERR
+JobFlavour = "longlunch"
queue 1
EOF1
    
    chmod u+x paok.sub
    
    condor_submit paok.sub
    
    #fi

done
