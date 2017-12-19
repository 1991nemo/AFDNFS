function nfs = AFDCtrlDesign(nfs)
%% lqr design
Along = nfs.dyn.long.ss.A;
Blong = nfs.dyn.long.ss.B;
Clong = eye(size(Along));
Dlong = zeros(size(Clong,1),size(Blong,2));

syslong = ss(Along, Blong, Clong, Dlong);

[Klong, ~, ~] = lqr(syslong,eye(size(Along))*10,eye(size(Blong,2)));

nfs.ctrl.lqr.long.K = Klong;

Alat = nfs.dyn.lat.ss.A;
Blat = nfs.dyn.lat.ss.B;
Clat = eye(size(Alat));
Dlat = zeros(size(Clat,1),size(Blat,2));

syslat = ss(Alat, Blat, Clat, Dlat);

[Klat, ~, ~] = lqr(syslat,eye(size(Alat))*2,eye(size(Blat,2)));

nfs.ctrl.lqr.lat.K = Klat;

