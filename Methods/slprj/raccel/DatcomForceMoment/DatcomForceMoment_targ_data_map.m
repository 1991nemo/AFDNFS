  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 134;
      section.data(134)  = dumData; %prealloc
      
	  ;% rtP.u
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.Constant1_Value
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 17;
	
	  ;% rtP.Constant_Value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 18;
	
	  ;% rtP.Constant2_Value
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 19;
	
	  ;% rtP.Constant4_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 20;
	
	  ;% rtP.Constant3_Value
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 21;
	
	  ;% rtP.SeaLevelTemperature_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 22;
	
	  ;% rtP.Limitaltitudetotroposhere_UpperSat
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 23;
	
	  ;% rtP.Limitaltitudetotroposhere_LowerSat
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 24;
	
	  ;% rtP.LapseRate_Gain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 25;
	
	  ;% rtP.uT0_Gain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 26;
	
	  ;% rtP.gLR_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 27;
	
	  ;% rtP.rho0_Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 28;
	
	  ;% rtP.AltitudeofTroposphere_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 29;
	
	  ;% rtP.LimitaltitudetoStratosphere_UpperSat
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 30;
	
	  ;% rtP.LimitaltitudetoStratosphere_LowerSat
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 31;
	
	  ;% rtP.gR_Gain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 32;
	
	  ;% rtP.Gain_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 33;
	
	  ;% rtP.Constant_Value_cddtuuqxak
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 34;
	
	  ;% rtP.alpha_BreakpointsData
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 35;
	
	  ;% rtP.gammaR_Gain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 44;
	
	  ;% rtP.Mach_BreakpointsData
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 45;
	
	  ;% rtP.altitude_BreakpointsData
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 47;
	
	  ;% rtP.CD_Table
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 50;
	
	  ;% rtP.CYb_Table
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 104;
	
	  ;% rtP.BetaSaturation_UpperSat
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 158;
	
	  ;% rtP.BetaSaturation_LowerSat
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 159;
	
	  ;% rtP.CL_Table
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 160;
	
	  ;% rtP.coefAdjust_Gain
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 214;
	
	  ;% rtP.Constant1_Value_n0vvf1ru2i
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 217;
	
	  ;% rtP.Constant_Value_gzdzpzihxe
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 218;
	
	  ;% rtP.Constant2_Value_eqjwl24tzr
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 219;
	
	  ;% rtP.Constant4_Value_bijw4dwdaf
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 220;
	
	  ;% rtP.Constant3_Value_emiujykzul
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 221;
	
	  ;% rtP.Constant6_Value
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 222;
	
	  ;% rtP.zero_Value
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 223;
	
	  ;% rtP.CYp1_Table
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 224;
	
	  ;% rtP.u_Value
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 278;
	
	  ;% rtP.Constant_Value_fhedlbhuxr
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 279;
	
	  ;% rtP.u_Value_jauwwxrr5h
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 280;
	
	  ;% rtP.BetaSaturation1_UpperSat
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 281;
	
	  ;% rtP.BetaSaturation1_LowerSat
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 282;
	
	  ;% rtP.CLad1_Table
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 283;
	
	  ;% rtP.Clp1_Table
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 337;
	
	  ;% rtP.Clq1_Table
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 391;
	
	  ;% rtP.Clr1_Table
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 445;
	
	  ;% rtP.Cmq1_Table
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 499;
	
	  ;% rtP.Cmad1_Table
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 553;
	
	  ;% rtP.Cnp1_Table
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 607;
	
	  ;% rtP.Cnr1_Table
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 661;
	
	  ;% rtP.Gain1_Gain
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 715;
	
	  ;% rtP.u_Value_agropua0cl
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 721;
	
	  ;% rtP.coefAdjust_Gain_blqcdygkok
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 722;
	
	  ;% rtP.Constant1_Value_e4b4arvsx4
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 725;
	
	  ;% rtP.Constant_Value_epkxnw5b5k
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 726;
	
	  ;% rtP.Constant2_Value_i0tusarllo
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 727;
	
	  ;% rtP.Constant4_Value_ebczl1p2kp
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 728;
	
	  ;% rtP.Constant3_Value_n2bp44blge
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 729;
	
	  ;% rtP.Constant1_Value_f1v4g1iait
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 730;
	
	  ;% rtP.delta_f_BreakpointsData
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 731;
	
	  ;% rtP.DCDI_Table
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 740;
	
	  ;% rtP.Constant1_Value_bhkzpq4cm3
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 1226;
	
	  ;% rtP.DCL_Table
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 1227;
	
	  ;% rtP.Constant2_Value_old3zd5smi
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 1713;
	
	  ;% rtP.DCm_Table
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 1714;
	
	  ;% rtP.Constant3_Value_nvs1o44prj
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 2200;
	
	  ;% rtP.delta_e_BreakpointsData
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 2201;
	
	  ;% rtP.DCDI_Table_ectqqf4lpu
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 2210;
	
	  ;% rtP.Constant1_Value_dvrrjd2vth
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 2696;
	
	  ;% rtP.DCL_Table_b2ogh4jov4
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 2697;
	
	  ;% rtP.Constant2_Value_n1gt4skuej
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 3183;
	
	  ;% rtP.DCm_Table_jpppnjjyiv
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 3184;
	
	  ;% rtP.Constant3_Value_ammrq4bbzx
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 3670;
	
	  ;% rtP.Constant6_Value_o2itzcqfbo
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 3671;
	
	  ;% rtP.Constant1_Value_jj4sc0nzo2
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 3672;
	
	  ;% rtP.Constant5_Value
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 3673;
	
	  ;% rtP.delta_a_BreakpointsData
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 3674;
	
	  ;% rtP.DCl_Table
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 3683;
	
	  ;% rtP.Constant4_Value_bxodvzr3wv
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 4169;
	
	  ;% rtP.DCn_Table
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 4170;
	
	  ;% rtP.Gain_Gain_gtonf3ckiq
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 4656;
	
	  ;% rtP.coefAdjust_Gain_jhgwt4xcre
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 4657;
	
	  ;% rtP.Gain1_Gain_gk1wozgh1p
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 4660;
	
	  ;% rtP.WeightForce_Value
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 4661;
	
	  ;% rtP.TrimThrust1_Value
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 4662;
	
	  ;% rtP.TrimThrust2_Value
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 4663;
	
	  ;% rtP.TrimThrust3_Value
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 4664;
	
	  ;% rtP.Throttle_Gain
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 4665;
	
	  ;% rtP.FromWs_Time0
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 4666;
	
	  ;% rtP.FromWs_Data0
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 4672;
	
	  ;% rtP.TrimThrust4_Value
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 4678;
	
	  ;% rtP.Constant1_Value_bylbexapfl
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 4679;
	
	  ;% rtP.Constant_Value_gi4rxypddg
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 4680;
	
	  ;% rtP.Constant2_Value_ntj1nxsmyj
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 4681;
	
	  ;% rtP.Constant4_Value_g531dn02hg
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 4682;
	
	  ;% rtP.Constant3_Value_irkjubdpiu
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 4683;
	
	  ;% rtP.Constant1_Value_ic5cse51j2
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 4684;
	
	  ;% rtP.Constant_Value_hfw2vld21b
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 4685;
	
	  ;% rtP.Constant2_Value_iq4hlvezb4
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 4686;
	
	  ;% rtP.Constant4_Value_p1gsoflfkl
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 4687;
	
	  ;% rtP.Constant3_Value_bfs2kyqhyj
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 4688;
	
	  ;% rtP.Xcp_Table
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 4689;
	
	  ;% rtP.Constant4_Value_lvvzxuwh5z
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 4743;
	
	  ;% rtP.zero1_Value
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 4744;
	
	  ;% rtP.Clb_Table
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 4745;
	
	  ;% rtP.Cm_Table
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 4799;
	
	  ;% rtP.Cnb_Table
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 4853;
	
	  ;% rtP.Constant2_Value_mwviqzbxqh
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 4907;
	
	  ;% rtP.Constant1_Value_g0n03q330k
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 4908;
	
	  ;% rtP.Constant_Value_ejuc1rn4ry
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 4909;
	
	  ;% rtP.Constant2_Value_oqrmwaotar
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 4910;
	
	  ;% rtP.Constant4_Value_jl0l41uur4
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 4911;
	
	  ;% rtP.Constant3_Value_gaexcfymgv
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 4912;
	
	  ;% rtP.Constant1_Value_hei4fwlj0u
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 4913;
	
	  ;% rtP.Constant_Value_fbwwe2lmsk
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 4914;
	
	  ;% rtP.Constant2_Value_d4ghahoovd
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 4915;
	
	  ;% rtP.Constant4_Value_iw11bz0kqi
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 4916;
	
	  ;% rtP.Constant3_Value_pp0fbeghm2
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 4917;
	
	  ;% rtP.Constant7_Value
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 4918;
	
	  ;% rtP.Constant8_Value
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 4919;
	
	  ;% rtP.Constant1_Value_ol4tirigyp
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 4920;
	
	  ;% rtP.Constant_Value_kouoqvqr2q
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 4921;
	
	  ;% rtP.Constant2_Value_gjwptupmqz
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 4922;
	
	  ;% rtP.Constant4_Value_cbj5azvbu2
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 4923;
	
	  ;% rtP.Constant3_Value_pwsvvqm1ni
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 4924;
	
	  ;% rtP.Constant1_Value_knfpzjs1ar
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 4925;
	
	  ;% rtP.Constant_Value_huxzftueqj
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 4926;
	
	  ;% rtP.Constant2_Value_oqyl4nphju
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 4927;
	
	  ;% rtP.Constant4_Value_ijxamwyxru
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 4928;
	
	  ;% rtP.Constant3_Value_idex1eazwv
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 4929;
	
	  ;% rtP.Constant3_Value_c0ie4jx1vv
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 4930;
	
	  ;% rtP.Constant5_Value_hu2bresth1
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 4931;
	
	  ;% rtP.WeightMoment_Value
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 4932;
	
	  ;% rtP.TrimThrust5_Value
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 4935;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% rtP.CD_dimSize
	  section.data(1).logicalSrcIdx = 134;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.CYb_dimSize
	  section.data(2).logicalSrcIdx = 135;
	  section.data(2).dtTransOffset = 3;
	
	  ;% rtP.CL_dimSize
	  section.data(3).logicalSrcIdx = 136;
	  section.data(3).dtTransOffset = 6;
	
	  ;% rtP.CYp1_dimSize
	  section.data(4).logicalSrcIdx = 137;
	  section.data(4).dtTransOffset = 9;
	
	  ;% rtP.CLad1_dimSize
	  section.data(5).logicalSrcIdx = 138;
	  section.data(5).dtTransOffset = 12;
	
	  ;% rtP.Clp1_dimSize
	  section.data(6).logicalSrcIdx = 139;
	  section.data(6).dtTransOffset = 15;
	
	  ;% rtP.Clq1_dimSize
	  section.data(7).logicalSrcIdx = 140;
	  section.data(7).dtTransOffset = 18;
	
	  ;% rtP.Clr1_dimSize
	  section.data(8).logicalSrcIdx = 141;
	  section.data(8).dtTransOffset = 21;
	
	  ;% rtP.Cmq1_dimSize
	  section.data(9).logicalSrcIdx = 142;
	  section.data(9).dtTransOffset = 24;
	
	  ;% rtP.Cmad1_dimSize
	  section.data(10).logicalSrcIdx = 143;
	  section.data(10).dtTransOffset = 27;
	
	  ;% rtP.Cnp1_dimSize
	  section.data(11).logicalSrcIdx = 144;
	  section.data(11).dtTransOffset = 30;
	
	  ;% rtP.Cnr1_dimSize
	  section.data(12).logicalSrcIdx = 145;
	  section.data(12).dtTransOffset = 33;
	
	  ;% rtP.DCDI_dimSize
	  section.data(13).logicalSrcIdx = 146;
	  section.data(13).dtTransOffset = 36;
	
	  ;% rtP.DCL_dimSize
	  section.data(14).logicalSrcIdx = 147;
	  section.data(14).dtTransOffset = 40;
	
	  ;% rtP.DCm_dimSize
	  section.data(15).logicalSrcIdx = 148;
	  section.data(15).dtTransOffset = 44;
	
	  ;% rtP.DCDI_dimSize_hvypykhf0h
	  section.data(16).logicalSrcIdx = 149;
	  section.data(16).dtTransOffset = 48;
	
	  ;% rtP.DCL_dimSize_i0jbywo0xh
	  section.data(17).logicalSrcIdx = 150;
	  section.data(17).dtTransOffset = 52;
	
	  ;% rtP.DCm_dimSize_oju4dybify
	  section.data(18).logicalSrcIdx = 151;
	  section.data(18).dtTransOffset = 56;
	
	  ;% rtP.DCl_dimSize
	  section.data(19).logicalSrcIdx = 152;
	  section.data(19).dtTransOffset = 60;
	
	  ;% rtP.DCn_dimSize
	  section.data(20).logicalSrcIdx = 153;
	  section.data(20).dtTransOffset = 64;
	
	  ;% rtP.Xcp_dimSize
	  section.data(21).logicalSrcIdx = 154;
	  section.data(21).dtTransOffset = 68;
	
	  ;% rtP.Clb_dimSize
	  section.data(22).logicalSrcIdx = 155;
	  section.data(22).dtTransOffset = 71;
	
	  ;% rtP.Cm_dimSize
	  section.data(23).logicalSrcIdx = 156;
	  section.data(23).dtTransOffset = 74;
	
	  ;% rtP.Cnb_dimSize
	  section.data(24).logicalSrcIdx = 157;
	  section.data(24).dtTransOffset = 77;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 158;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 34;
      section.data(34)  = dumData; %prealloc
      
	  ;% rtB.nhxk0ib0lj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.jf5nt45ccr
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.hzbuxpmezj
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.pw5gjuojru
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.fsutp3ayo3
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% rtB.idhxicsqcr
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 15;
	
	  ;% rtB.mml2ndjd5d
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 16;
	
	  ;% rtB.hbts5j1pqq
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 17;
	
	  ;% rtB.f2a4bnffor
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 26;
	
	  ;% rtB.ookv2bvvls
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 27;
	
	  ;% rtB.phcwtlgyip
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 28;
	
	  ;% rtB.bbuiyhe1o5
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 29;
	
	  ;% rtB.mxt20vlpck
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 30;
	
	  ;% rtB.ianx2c50xl
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 31;
	
	  ;% rtB.n3teuvsdd5
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 32;
	
	  ;% rtB.kacxif5qn0
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 33;
	
	  ;% rtB.oxq5mf1mg3
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 34;
	
	  ;% rtB.iayveggtaq
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 35;
	
	  ;% rtB.il1zzs3oim
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 36;
	
	  ;% rtB.lanxaiurnw
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 37;
	
	  ;% rtB.hxsqezn2an
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 38;
	
	  ;% rtB.n2spnyfef4
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 41;
	
	  ;% rtB.ab5d34lf4o
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 42;
	
	  ;% rtB.jjpibu4asu
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 43;
	
	  ;% rtB.igwvaibikt
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 44;
	
	  ;% rtB.jwtgtch3mu
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 47;
	
	  ;% rtB.m1nsvprq1z
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 50;
	
	  ;% rtB.bdzrxsq0jb
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 53;
	
	  ;% rtB.dp5pi2avlk
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 62;
	
	  ;% rtB.ilvgb1vukq
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 65;
	
	  ;% rtB.kies3oo3id
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 68;
	
	  ;% rtB.pg2hzggfwd
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 71;
	
	  ;% rtB.lzr1wnncjo
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 74;
	
	  ;% rtB.jvmj3dgdoq
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 80;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtDW.lshsqezqdg
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.glhg1qagai
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.noao4ocazt
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.davtpmukf5
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.ou0twhytn5
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.iub22gul40
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.hgbmrfgo34
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.bdnvmlo1qe
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtDW.l43hqho0yh.TimePtr
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.kr5bwg1sps.LoggedData
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.f2fmemooxc.LoggedData
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.ir3clx43vq.LoggedData
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.ntqydpj2su.LoggedData
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.hjm1dzxvpi.LoggedData
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtDW.eavb5jrhyr
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.hod3grnuyb
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.m54rowgddh
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.c3s1ykl5ma
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.htx1g0xx41
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.mi4wxn4zbd
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.cffy3oatmx.PrevIndex
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 309997958;
  targMap.checksum1 = 4152278500;
  targMap.checksum2 = 3176591357;
  targMap.checksum3 = 2740593875;

