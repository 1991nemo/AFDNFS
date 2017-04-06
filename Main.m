clc; clear all; close all;
output = 'true';
base = pwd;
mdir = fullfile(base,'Methods');
cd(mdir);
nfs = TransferFunction('Plot','true');
if strcmpi(output,'true')
    disp('---------------------------------------------------------------------');
    disp('System Linear State-Space');
    nfs.dyn.linsys
    disp('---------------------------------------------------------------------');
    disp('System Linear Transfer Function');
    tf(nfs.dyn.linsys)
    disp('---------------------------------------------------------------------');
    disp('Longitudinal Characteristic Equation');
    nfs.dyn.long.cheq
    disp('---------------------------------------------------------------------');
    disp('Lateral Characteristic Equation');
    nfs.dyn.lat.cheq
    disp('---------------------------------------------------------------------');
    disp('Longitudinal Poles');
    nfs.dyn.long.pol
    disp('---------------------------------------------------------------------');
    disp('Lateral Poles');
    nfs.dyn.lat.pol
    disp('---------------------------------------------------------------------');
    disp('');
end;
cd(base);