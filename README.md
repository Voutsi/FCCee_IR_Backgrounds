# FCCee_IR_Backgrounds
Tools and documentation to study FCCee interaction region backgrounds
# Table of contents
[Using Guinea-Pig to generate interaction region backgrounds] (#GP)

[Generating e<sup>-</sup> e<sup>+</sup> pairs] (#pairs)

[GP configuration parameters] (#pars)

[Generating large amount of data with GP] (#data)

[GP production of \gamma\gamma hadrons]  (#hadrons)



<a name="GP"></a>
## Using Guinea-Pig to generate interaction region backgrounds


Guinea-Pig software can be downloaded from:

https://gitlab.cern.ch/clic-software/guinea-pig

You will find an installation guide at the above site.

<a name="pairs"></a>
### Generating e<sup>-</sup> e<sup>+</sup> pairs 

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
    nn=${i}*8
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

<a name="hadrons"></a>
###GP production of \gamma\gamma hadrons