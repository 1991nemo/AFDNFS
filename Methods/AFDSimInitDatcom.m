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
nfs=PlaneData('SI');
load('SampleDatcomData.mat');
% Trim Condition =========================================================%
% [trim_con]=AFDTrim(nfs);
[trim_con]=AFDTrimDatcom(nfs);
nfs.trim.alpha=trim_con{1};
nfs.trim.delta_e=trim_con{2};
nfs.trim.thrust=trim_con{3};

nfs.crusevelvec=[nfs.crusevel*cos(nfs.trim.alpha), 0, nfs.crusevel*sin(nfs.trim.alpha)]';
nfs.attitude0=[0,nfs.trim.alpha,0]';
desired.height=-nfs.altitude;
desired.pitch=(nfs.trim.alpha);
desired.phi=0;
desired.q=0;

% [F_Body,M_Body]=ForceMoment(nfs.crusevelvec,[0 0 0],[nfs.trim.delta_e 0 0 0],...
%     [0 nfs.trim.alpha 0],[0,0,-nfs.altitude],nfs.trim.thrust,0,nfs)