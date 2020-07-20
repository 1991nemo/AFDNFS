%=========================================================================%
%                  Sharif University of Technology                        %
%                  Aerospace Engineering Department                       %
%                    Flight Dynamics and Control                          %
%-------------------------------------------------------------------------%
% Written by:                   Amir H. Khodabakhsh,                      %
% Student Code:                 93208448                                  %
% Date:                         Octrober, 2014                            %
%=========================================================================%
%                     Avanced Flight Dynamics (AFD)                       %
%                    Nonlinear Flight Simulator (NFS)                     %
%-------------------------------------------------------------------------%
%                               AFDNFS                                    %
%=========================================================================%
clc; clear all; close all;
format long;
nfs=PlaneData('SI');%('Imperial');
nfs = NFSUncertainty(nfs);
nfs = NFSCoordinateInit(nfs);
nfs = NFSMrasurement(nfs);
% load('SampleDatcomData.mat');
% Trim Condition =========================================================%
[trim_con]=AFDTrim(nfs);
% [trim_con]=AFDTrimDatcom(nfs);
nfs.trim.alpha = trim_con{1};
nfs.trim.beta = 0;
nfs.trim.delta_e = trim_con{2};
nfs.trim.delta_f = 0;
nfs.trim.delta_a = 0;
nfs.trim.delta_r = 0;
nfs.trim.thrust = trim_con{3};

nfs.crusevelvec=nfs.crusevel*[cos(nfs.trim.alpha)*cos(nfs.trim.beta), ...
              sin(nfs.trim.beta), sin(nfs.trim.alpha)*cos(nfs.trim.beta)]';
nfs.attitude0=[0,nfs.pathangle + nfs.trim.alpha,0]';
nfs.desired.height=-nfs.altitude;
nfs.desired.pitch=(nfs.pathangle + nfs.trim.alpha);
nfs.desired.phi=0; 
nfs.desired.q=0;

% [F_Body,M_Body]=ForceMoment(nfs.crusevelvec,[0 0 0],[nfs.trim.delta_e 0 0 0],...
%     [0 nfs.trim.alpha 0],[0,0,-nfs.altitude],nfs.trim.thrust,0,nfs);
% disp('Force = '); disp(F_Body);
% disp('Moment = '); disp(M_Body);
% clear F_Body M_Body;


nfs = TransferFunction(nfs,'Plot','false');
nfs = AFDCtrlDesign(nfs);

NFSOnLoad;
dictionaryObj = Simulink.data.dictionary.open([wd,'\NFSDatabase.sldd']);
sectionObj = dictionaryObj.getSection('Design Data');
temp = sectionObj.getEntry('nfs');
setValue(temp,nfs);
saveChanges(dictionaryObj);
dictionaryObj.close();
