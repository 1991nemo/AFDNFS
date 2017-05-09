clc; clear all; close all;
output = 'true';
base = pwd;
mdir = fullfile(base,'Methods');
cd(mdir);
nfs = TransferFunction('Plot','true');
if strcmpi(output,'true')
%     disp('---------------------------------------------------------------------');
%     disp('System Linear State-Space');
%     nfs.dyn.linsys
%     disp('---------------------------------------------------------------------');
%     disp('System Linear Transfer Function');
%     tf(nfs.dyn.linsys)
    disp('---------------------------------------------------------------------');
    disp('Longitudinal Characteristic Equation');
    nfs.dyn.long.correct.cheq
    disp('---------------------------------------------------------------------');
    disp('Lateral Characteristic Equation');
    nfs.dyn.lat.correct.cheq
    disp('---------------------------------------------------------------------');
    disp('Longitudinal Poles');
    nfs.dyn.long.correct.pole
    disp('---------------------------------------------------------------------');
    disp('Lateral Poles');
    nfs.dyn.lat.correct.pole
    disp('---------------------------------------------------------------------');
    disp('');
end;
cd(base);
