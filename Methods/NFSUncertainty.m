function nfs = NFSUncertainty(nfs)
nfs.Uncertainty.Noise.SampleTime = 1;
nfs.Uncertainty.Turbulence.VonKarman.Seed = [23341 23342 23343 23344];
nfs.Uncertainty.Turbulence.VonKarman.ScaleLength = 762;
nfs.Uncertainty.Turbulence.Dryden.Seed = [23341 23342 23343 23344];
nfs.Uncertainty.Turbulence.Dryden.ScaleLength = 533.4;
