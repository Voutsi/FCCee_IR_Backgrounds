# FCCee_IR_Backgrounds
Tools and documentation to study FCCee interaction region backgrounds
# Table of contents
[Using Guinea-Pig to generate interaction region backgrounds] (#GP)

[Generating e<sup>-</sup> e<sup>+</sup> pairs] (#pairs)

[GP configuration parameters] (#pars)

[Generating large amount of data with GP] (#data)

[GP production of \gamma\gamma hadrons]  (#hadrons)




## Using Guinea-Pig to generate interaction region backgrounds <a name="GP"></a>


Guinea-Pig software can be downloaded from:

https://gitlab.cern.ch/clic-software/guinea-pig

You will find an installation guide at the above site.


### Generating e<sup>-</sup> e<sup>+</sup> pairs <a name="pairs"></a>

In order to run Guinea-Pig (hereafter GP) and generate e<sup>-</sup> e<sup>+</sup> pair background, one should provide the relevant accelerator (beam) parameters, plus some steering parameters to run the software. Those parameters are set in the file acc.dat.
Currently, one can find the four following accelerators, where the beam parameters correspond to the values considered for FCC CDR (2019).
* FCCee Z working point (Ecm = 91.2 GeV): FCCee_Z
* FCCee W working point (Ecm = 160 GeV): FCCee_W
* FCCee ZH working point (Ecm = 240 GeV): FCCee_ZH
* FCCee Top working point (Ecm = 365 GeV): FCCee_Top

and the following 2 sets of configuration parameters:
* FCCee_Z
* FCCee_Top

It is recommended to run the FCCee Z accelerator together with the FCCee_Z parameters, while the other 3 accelerators can be run with the FCCee_Top parameters.

#### Discussion on Guinea-Pig parameters

GP slices the bunches longitudinally (along Z) and divides the transverse space around the bunches into cells. The macroparticles are tracked inside this grid, where GP calculates the EM fields inside each cell. The finer the segmentation the more accurate the results, but obviously the running time can increase dramatically. Studies of the beam-beam effects on the luminosity measurements (together with other beam-beam related studies) showed that for optimal results the interaction region diamond should be segmented in 2 slices (cells) in longitudinal (transverse) direction. Such a segmentation leads to ~1 week of running time for the Z working point. Clearly this is too long, and as we will see, such segmentation is not needed for background studies. Below we will point GP parameter configurations that produce reliable results in a reasonable amount of time.

The table shows the results for pairs obtained at Top working point, for grids of different granularities. nz is the number of slices, while nx and ny are the number of cells in transverse direction.

nz | nx | ny | pairs | Etot (TeV) | time (min)
--- | --- | --- | ---| --- | --- 
30 | 64 | 64 | 5324 | 5.4 | < 1
60 | 64 | 64 | 5498 | 5.0 | < 1.5
90 | 64 | 64 | 5564 | 5.4 | ~1.5
120 | 64 | 64 | 5398 | 5.7 | ~3
120 | 128 | 128 | 5660 | 5.6 | ~6
240 | 256 | 256 | 5580 | 6.0 | ~100

We see that a granularity finer by a factor of 128 (which comes together with an increase in running time ~100) doesn't bring a significant change to the results. In fact, it looks like they are independent of granularity (at lease for the range of values shown in the table). However, we need to keep in mind that the results for the pairs fluctuate from bunch crossing to bunch crossing (due to the different seed of GP). The size of the fluctuations is shown in figure below:

![alt text]( https://github.com/Voutsi/FCCee_IR_Backgrounds/blob/master/doc/GP_seed_study.png "Fluctuations at # of pairs and total energy for different GP seeds at Top working point")

Thud, in order to understand better the numerical stability of the code, we will run a large number (200) of GP simulation for each parameter configuration and will compare the mean values.

##### Top parameters

The size of the interaction region diamond along x, y, z is respectively 0.04mm, 50nm, 1.1mm. With an envelope of cutx = 6xσ<sub>x</sub>, cuty = 10xσ<sub>y</sub> and cutz = 3xσ<sub>z</sub> a reasonable slicing would be: 75-150 slices along z, 60-120 along x and 125-250 along y.

cut_z | cut_x | cut_y | nz | nx | ny | grids | pairs | Etot (GeV) | Reaching VXD | Missed | time (min) | Scenario
--- | --- | --- | ---| --- | --- | --- | --- | --- | --- | --- | --- | ---
3 | 6 | 10 | 75 | 60 | 125 | 7 | 5436±6 | 5689±50 | 20287 | ~0.008 | ~2 | 1
2 | 6 | 10 | 50 | 60 | 125 | 7 | 5465±10 | 5659±56 | 20529 | ~0.006 | <2 | 2
2 | 6 | 10 | 50 | 60 | 125 | 1 | 5466±8 | 5630±51 | 40797 | ~0.006 | ~1 | 3
2 | 6 | 10 | 100 | 120 | 250 | 7 | 5471±10 | 5691±68 |  | ~0.009 | ~10 | 4
2 | 6 | 10 | 200 | 120 | 250 | 7 | 5478±9 | 5602±54 | 21112 | ~0.01 | ~30 | 5
3 | 6 | 10 | 150 | 120 | 250 | 7 | 5475±10 | 5783±51 | 21094 | <0.01 | ~25 | 6
3 | 6 | 10 | 150 | 120 | 250 | 1 | 5488±8 | 5623±48 | 41582 | <0.01 | ~5 | 7
3 | 6 | 10 | 300 | 120 | 250 | 7 | 5503±8 | 5694±48 | 21328 | ~0.01 | >60 | 8

##### Z parameters

The shape of the bunch is very elongated, thus the rather large envelope at X and Y directions. The size of the interaction region diamond along x, y, z is respectively ~0.12mm, ~20nm and ~0.3mm. The slices/cells should be smaller than that. Taking into account the size of the envelope and of the interaction region diamond, 160 cells along X and 340 along Y(meaning the IR diamond is segmented to 10 cells) sound reasonble. Along Z, with an envelope twice larger than the bunch length (cut_z=2), 320 slices means a segmentation to 2 cells, while 640 to 4. These numbers will scale by a factor of 0.66 if we chose cut_z=3. The table below shows the values for some indicative results for pairs wrt various gp parameters scenarios. The presented results are averaged over 200BXs and the uncertainty corresponds to the systematic uncertainty due to the random seed.

cut_z | cut_x | cut_y | nz | nx | ny | grids | pairs | Etot (GeV) | Missed | time (min) | Scenario
--- | --- | --- | ---| --- | --- | --- | --- | --- | --- | --- | ---
3 | 150 | 60 | 61 | 1600 | 640 | 7 | 1460±4.3 | 499.6±9.5 | 0.04 | < 200 | 1
2 | 150 | 60 | 61 | 1600 | 640 | 1 | 1524±4.2 | 541.8±6.9 | 0.004 | > 45 | 2
2 | 150 | 60 | 61 | 800 | 320 | 1 | 1514±4.8 | 537.1±8.3 | <0.004 | > 7 | 3
2 | 150 | 60 | 128 | 320 | 320 | 1 | 1541±5.3 | 569.3±8.7 | 0.003 | ~35 | 4
2 | 150 | 60 | 256 | 320 | 320 | 1 | 1533±6.5 | 572.3±11.1 | 0.003 | ~ 200 | 5

and the graph depicts the pairs and the total energy versus the scenario:

![alt text]( https://github.com/Voutsi/FCCee_IR_Backgrounds/blob/master/doc/Z_GP_par_scan.png "Results for various scenaria")


#### Running Guinea-Pig

To run GP you should type the following:

YOUR_INSTALL_DIR/bin/guinea $ACC #PAR output

e.g.

YOUR_INSTALL_DIR/bin/guinea FCCee_Z FCCee_Z output

output it is the produced log file, and it can be given any name. Below we will try to explain the main GP configuration parameters. Each GP run corresponds to 1 bunch crossing.

<a name="pars"></a>
#### GP configuration parameters

<a name="data"></a>
### Generating large amount of data with GP

One can use the script at:

https://github.com/Voutsi/FCCee_IR_Backgrounds/blob/master/eepairs/sub_gp_pairs.sh

that sends a user defined number of bunch crossings to be generated in parallel in Condor. You should modify accordingly the following parts of the script:


```shell
nruns=100
```
defines the number of bunch crossings to be generated

```shell
ROOTDIR=/afs/cern.ch/user/v/voutsina/Work/FCCeeBKG_WrapUp/eepairs
```
This variable defines the directory where the results will be stored. The script will generate there a new directory, data${i} for the ith generated bunch crossing.

Command
```shell
sed -i -e 's/rndm_seed=1/rndm_seed='${nn}'/g' acc.dat
```
Changes the random seed for the ith bunch crossing according to the pattern
```shell
    nn=${i}*100000
```
Feel free to modify the pattern, but have in mind that if you run N BXs with the same seed, you will generate N times the same data.

In the following line
```shell
/afs/cern.ch/user/v/voutsina/Work/testarea/CodeTest/GP++/guinea-pig.r3238/src/guinea FCCee_Top FCCee_Top output
```
you should replace the path where your guinea executable is located, the desired accelerator and configuration-parameters names and the desired output file name.

The queueing in Condor is defined by the following line
```shell
+JobFlavour = "tomorrow"
```
For the set of parameters FCCee_Z, featuring an estimating running time of few hours, a job flavour "workday" is recommended. For the  set of parameters FCCee_Top, job flavour "longlunch" should be enough.

#### Running full simulation (only for ILCSOFT users)

Here we describe how to run the full simulation (DD4Hep), using ddsim. First we need to convert the GP generated data (pairs.dat) to a format appropiate for ddsim (.hepevt). For that we use the python script
https://github.com/Voutsi/FCCee_IR_Backgrounds/blob/master/eepairs/pairsToHepevt.py
The usage is the following:
```shell
python pairsToHepevt.py --file <pairs.dat> --angle <<15>>
```
The argument "--angle 15" applies the Lorentz boost due to the crossing angle. The value is half the crossing angle in mrad.
Alternatively, one can apply the Lorentz boost during simulation. The two ways are equivalent, but please keep in mind to apply the boost only once!

In order to convert many GP generated file, the user can run the script
https://github.com/Voutsi/FCCee_IR_Backgrounds/blob/master/eepairs/pairsGP_hepevt_serial.sh
It will parse the directories created by sub_gp_pairs.sh during the previous, convert the pairs.dat files to .hepevt (optionally apply the boost), and copy the .hepevt file to the same directory the corresponding .dat file resides. This script is serial. The pairsToHepevt.py is very fast, and if the user wants to convert up to few hundred files, there is not need to go for parallel processing.

Then the user can run the full simulation by running the script
https://github.com/Voutsi/FCCee_IR_Backgrounds/blob/master/eepairs/sub_pairs_sim.sh

This script will also parse the same directory structure, use the .hepevt file as input, run the simulation, and copy the .slcio file to the same directory where the corresponding .hepevt file resides. So in principle, the user can run the generation, conversion to hepevt format and full simulation almost out of the box. Things needed to be edited/paid attention to are:
* Setting the environment variables ROOTDIR and COMPACTFILE to point to the desired directory path where the user wants to store the data and to the path where the detector model compact file is
* Modify the following argument in sub_pairs_sim.sh: 
```shell 
source /afs/cern.ch/work/v/voutsina/guineapig++/guinea-pig.r3238/data/PairsZ/BeamParTest/Pairs/Geometry/init_ilcsoft.sh 
``` 
to point to the location of the initialisation script of the desired ILCSoft version
* and to pay attention to apply the boost once: currently it is applied during simulation

#### Analysing the data (only for ILCSOFT users)

Marlin processors used to analyse the simulated data. They were used for CDR results.
In order to compile them: please initialise ILCSoft environment first.

```shell
mkdir build; cd build
cmake -C $ILCSOFT/ILCSoft.cmake ..
make install
```

This will create a library for HitAnalysis processor, that should be then added to MARLIN_DLL variable:
```shell
export MARLIN_DLL=/path_to_the_library/HitAnalysis.so:$MARLIN_DLL
```

In the subdirectory steering is provided an initial simple Marlin steering file. It takes as input the simulated file(s) of lcio format created with ddsim in the previos steps

```shell
<parameter name="LCIOInputFiles"> INPUTFILE.slcio </parameter>
```

The user can put the path of multiple files. 

```shell
    <parameter name="MaxRecordNumber" value="0" />
```
means that the script will run over all events in the files. Alternatively the user can set the desired number of events. Also it should be ensured that the geometry file set at:
```shell
    <parameter name="DD4hepXMLFile" type="string"> COMPACTFILE.xml  </parameter>
```
under the InitDD4hep processor it is exactly the same as the one used for full simulation. This steering file contains the minimal number of Marlin processors in order to analyse a full simulated file of LCIO format and produce an output root file having a tree that holds some useful variables for background analysis. E.g, in this tree one can find:
* simX, simY, simZ showing the positions of the bkg hits
* Secondary: if true, the hit comes from a secondary particle, produced via the interaction of the pairs with the detector material
* vtxX, vtxY, vtxZ showing the vertex of the particle that created the hit
* simPDG it gives the PDG code of the particle that made the hit
* hitTime: the time that the hit was created
* hitNrg: the energy deposited at the hit
* SubDet, Layer: giving the subdetector and the layer that the hit is located

along with some other variables and plots, out of which quite interesting is the gNoOfHits histogram that shows the average number of hits per subdetector. To run this steering file the user should first source the ILCSOFT (and add the path of the library to MARLIN_DLL) and then simply "Marlin steer_marlin.xml".


<a name="hadrons"></a>
### GP production of \gamma\gamma hadrons

In order to produce \gamma\gamma to hadrons with GP, we need to add the following commands inside the configuration file acc.dat

```shell
hadron_ratio=100000;
do_hadrons=3;
store_hadrons=1;
```
while switching off pair production:
```shell
do_pairs= 0;
```

"do_hadrons = 3;" will make GP to produce a hadron.dat file, which contains the produced partons, with the same cross-section parametrisation as Pythia does. "hadron_ratio=100000;" is the weight factor with which the cross section of the
hadronic interaction is scaled. As a second step, we invoke Pythia to do the fragmentation. To do so, we use the "hades" library from Daniel Schulte, which allows to feed the GuineaPig's output to Pythia. Finally we translate the Pythia's output to .HEPEvt style events. To perform the last 2 steps, we can use the tar file at

https://github.com/Voutsi/FCCee_IR_Backgrounds/blob/master/ggToHadrons/hadron.tar.gz

This file was made by Dominik Arominski, and contains the HADES library. Please unpack it and follow the instructions given in the README file.
