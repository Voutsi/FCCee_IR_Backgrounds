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
- item FCCee Z working point (Ecm = 91.2 GeV): FCCee_Z
- item FCCee W working point (Ecm = 160 GeV): FCCee_W
- item FCCee ZH working point (Ecm = 240 GeV): FCCee_ZH
- item FCCee Top working point (Ecm = 365 GeV): FCCee_Top

and the following 2 sets of configuration parameters:
- item FCCee_Z
- item FCCee_Top

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

#### Analysing the data (only for ILCSOFT users)

Marlin processors used to analyse the simulated data. They were used for CDR results.
In order to compile them: please initialise ILCSoft environment first.

```shell
mkdir build; cd build
cmake -C $ILCSOFT/ILCSoft.cmake ..
make install
```

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
