clc; clear all; close all;
datcom_out=datcomimport('----for006.dat');
nfs.aero.cLdelta_e=[ 5.6     0.011
                    -0.0    -0.000
                    -5.9    -0.011
                    -14.3   -0.026];
nfs.aero.cLdelta_e=nfs.aero.cLdelta_e(end:-1:1,:)
