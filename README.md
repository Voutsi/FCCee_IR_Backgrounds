# FCCee_IR_Backgrounds
Tools and documentation to study FCCee interaction region backgrounds

## Using Guinea-Pig to generate interaction region backgrounds

Guinea-Pig software can be downloaded from:

https://gitlab.cern.ch/clic-software/guinea-pig

You will find an installation guide at the above site.

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
output it is the produced log file, and it can be given any name. Below we will try to explain the main GP configuration parameters.

#### GP configuration parmeters