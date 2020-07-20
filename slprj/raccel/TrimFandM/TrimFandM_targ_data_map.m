  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
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
      section.nData     = 133;
      section.data(133)  = dumData; %prealloc
      
	  ;% rtP.FlatEarthtoLLA_LL0
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.DragCoefficient_cD0
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% rtP.LiftCoefficient_cL0
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% rtP.CompareToConstant_const
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% rtP.CompareToConstant_const_lqd2aov4ko
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% rtP.CompareToConstant_const_gbmczedm2k
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% rtP.CompareToConstant_const_ohveajuklj
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% rtP.CompareToConstant_const_m35urglgce
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% rtP.CompareToConstant_const_nfpclnqcaz
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 9;
	
	  ;% rtP.LiftCoefficient_meanchord
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 10;
	
	  ;% rtP.FlatEarthtoLLA_psi
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 11;
	
	  ;% rtP.FromWs_Time0
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 12;
	
	  ;% rtP.FromWs_Data0
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% rtP.Constant4_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 24;
	
	  ;% rtP.Gain_Gain
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 27;
	
	  ;% rtP.ChSign_Gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 28;
	
	  ;% rtP.ChSign1_Gain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 29;
	
	  ;% rtP.Zero_Value
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 30;
	
	  ;% rtP.ChSign2_Gain
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 31;
	
	  ;% rtP.SeaLevelTemperature_Value
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 32;
	
	  ;% rtP.RefAlt_Value
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 33;
	
	  ;% rtP.Constant5_Value
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 34;
	
	  ;% rtP.Limitaltitudetotroposhere_UpperSat
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 37;
	
	  ;% rtP.Limitaltitudetotroposhere_LowerSat
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 38;
	
	  ;% rtP.LapseRate_Gain
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 39;
	
	  ;% rtP.uT0_Gain
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 40;
	
	  ;% rtP.gLR_Value
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 41;
	
	  ;% rtP.rho0_Gain
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 42;
	
	  ;% rtP.AltitudeofTroposphere_Value
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 43;
	
	  ;% rtP.LimitaltitudetoStratosphere_UpperSat
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 44;
	
	  ;% rtP.LimitaltitudetoStratosphere_LowerSat
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 45;
	
	  ;% rtP.gR_Gain
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 46;
	
	  ;% rtP.Gain_Gain_i2ygq2tusg
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 47;
	
	  ;% rtP.Wingarea_Value
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 48;
	
	  ;% rtP.Wingspan_Value
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 49;
	
	  ;% rtP.clbeta_Gain
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 50;
	
	  ;% rtP.Constant3_Value
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 51;
	
	  ;% rtP.cldelta_a_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 55;
	
	  ;% rtP.cldelta_r_Gain
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 56;
	
	  ;% rtP.Constant6_Value
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 57;
	
	  ;% rtP.clp_Gain
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 60;
	
	  ;% rtP.clr_Gain
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 61;
	
	  ;% rtP.Wingspan_Value_abjhsc0f24
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 62;
	
	  ;% rtP.u_Gain
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 63;
	
	  ;% rtP.Wingchord_Value
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 64;
	
	  ;% rtP.Cm0_Value
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 65;
	
	  ;% rtP.cmalpha_Gain
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 66;
	
	  ;% rtP.cmdelta_f_Gain
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 67;
	
	  ;% rtP.cmdelta_e_Gain
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 68;
	
	  ;% rtP.Constant1_Value
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 69;
	
	  ;% rtP.cmalphadot_Gain
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 72;
	
	  ;% rtP.cmq_Gain
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 73;
	
	  ;% rtP.Wingchord_Value_pdh1mmrkaf
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 74;
	
	  ;% rtP.u_Gain_c3gtfmblii
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 75;
	
	  ;% rtP.gammaR_Gain
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 76;
	
	  ;% rtP.cmM_Gain
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 77;
	
	  ;% rtP.Wingspan2_Value
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 78;
	
	  ;% rtP.cnbeta_Gain
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 79;
	
	  ;% rtP.cndelta_a_Gain
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 80;
	
	  ;% rtP.cndelta_r_Gain
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 81;
	
	  ;% rtP.cnp_Gain
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 82;
	
	  ;% rtP.cnr_Gain
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 83;
	
	  ;% rtP.Wingspan_Value_e2odjstrw4
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 84;
	
	  ;% rtP.u_Gain_allopj2sjw
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 85;
	
	  ;% rtP.TrimThrust5_Value
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 86;
	
	  ;% rtP.TrimThrust5_Value_aggklib54h
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 89;
	
	  ;% rtP.Constant7_Value
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 92;
	
	  ;% rtP.cLalpha_Gain
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 95;
	
	  ;% rtP.cLdelta_e_Gain
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 96;
	
	  ;% rtP.cLdelta_f_Gain
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 97;
	
	  ;% rtP.cLalphadot_Gain
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 98;
	
	  ;% rtP.cLq_Gain
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 99;
	
	  ;% rtP.u_Gain_nvhs5kychw
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 100;
	
	  ;% rtP.CLM_Gain
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 101;
	
	  ;% rtP.InducedDrag_Gain
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 102;
	
	  ;% rtP.cDalpha_Gain
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 103;
	
	  ;% rtP.cDdelta_f_Gain
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 104;
	
	  ;% rtP.cDdelta_e_Gain
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 105;
	
	  ;% rtP.cDdelta_a_Gain
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 106;
	
	  ;% rtP.cDdelta_r_Gain
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 107;
	
	  ;% rtP.cDM_Gain
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 108;
	
	  ;% rtP.ChSign_Gain_k0w4nqg0k2
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 109;
	
	  ;% rtP.ChSign1_Gain_n4wwtfjx2h
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 110;
	
	  ;% rtP.ChSign2_Gain_effoydn3u1
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 111;
	
	  ;% rtP.WingArea_Value
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 112;
	
	  ;% rtP.ChSign_Gain_gtanyi5b3f
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 113;
	
	  ;% rtP.ChSign1_Gain_nkytdev4sk
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 114;
	
	  ;% rtP.Zero_Value_mumexc0o4r
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 115;
	
	  ;% rtP.ChSign2_Gain_knade2nq5x
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 116;
	
	  ;% rtP.cYbeta_Gain
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 117;
	
	  ;% rtP.cYdelta_a_Gain
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 118;
	
	  ;% rtP.cYdelta_r_Gain
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 119;
	
	  ;% rtP.cYp_Gain
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 120;
	
	  ;% rtP.cYr_Gain
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 121;
	
	  ;% rtP.Wingspan_Value_n3iuon0ekq
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 122;
	
	  ;% rtP.u_Gain_fra5iqtqqa
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 123;
	
	  ;% rtP.Constant_Value
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 124;
	
	  ;% rtP.Constant1_Value_gzve1ir0t2
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 125;
	
	  ;% rtP.Constant2_Value
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 126;
	
	  ;% rtP.Constant1_Value_axlwkx0upk
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 127;
	
	  ;% rtP.Constant_Value_nc3vt5cgfc
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 128;
	
	  ;% rtP.Constant_Value_cvu4p50c1r
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 129;
	
	  ;% rtP.Constant_Value_m5g2px2tx2
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 130;
	
	  ;% rtP.f_Value
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 131;
	
	  ;% rtP.Bias_Bias
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 132;
	
	  ;% rtP.Constant2_Value_mq0ugbio0d
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 133;
	
	  ;% rtP.Bias1_Bias
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 134;
	
	  ;% rtP.Bias_Bias_d2nkgtoec1
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 135;
	
	  ;% rtP.Gain_Gain_hksk452z1z
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 136;
	
	  ;% rtP.Bias1_Bias_gu4d3m1zk1
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 137;
	
	  ;% rtP.Constant_Value_ch1bn1coed
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 138;
	
	  ;% rtP.Constant3_Value_g2ewzhwyko
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 139;
	
	  ;% rtP.Constant_Value_mxa0cv5de4
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 140;
	
	  ;% rtP.Constant1_Value_pwlq2ttr5w
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 141;
	
	  ;% rtP.Bias_Bias_b2ra0lewbe
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 142;
	
	  ;% rtP.Constant2_Value_mqqkn141fi
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 143;
	
	  ;% rtP.Bias1_Bias_eoswi2rhti
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 144;
	
	  ;% rtP.Bias_Bias_kpaulxvgkm
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 145;
	
	  ;% rtP.Constant2_Value_h4ldodunib
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 146;
	
	  ;% rtP.Bias1_Bias_cgno1ebhcg
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 147;
	
	  ;% rtP.Bias_Bias_mvispiykz2
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 148;
	
	  ;% rtP.Gain_Gain_lt1rzsj1bc
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 149;
	
	  ;% rtP.Bias1_Bias_bohiusfzhl
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 150;
	
	  ;% rtP.Bias_Bias_hfb13vpfjg
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 151;
	
	  ;% rtP.Constant2_Value_a3oznwkh02
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 152;
	
	  ;% rtP.Bias1_Bias_hdwwrgv0bw
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 153;
	
	  ;% rtP.TrimThrust1_Value
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 154;
	
	  ;% rtP.TrimThrust2_Value
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 155;
	
	  ;% rtP.TrimThrust3_Value
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 156;
	
	  ;% rtP.Throttle_Gain
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 157;
	
	  ;% rtP.TrimThrust4_Value
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 158;
	
	  ;% rtP.Gain1_Gain
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 159;
	
	  ;% rtP.mass_Value
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 160;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 133;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
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
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% rtB.cewmuklpud
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.c155b3ttul
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% rtB.a3vyc4l10x
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% rtB.oouqhb3v3v
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% rtB.gqpi3oabc5
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% rtB.lbnjpcgymq
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% rtB.lqji0le141
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% rtB.iwltmc0fj1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% rtB.k1zmldxyil
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% rtB.eitentvc2c
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 11;
	
	  ;% rtB.n20ebdvrmd
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% rtB.dkxpu1nqs1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 17;
	
	  ;% rtB.h5b40zrgbx
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 20;
	
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
    nTotSects     = 3;
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
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% rtDW.ia5ajb52kh.TimePtr
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.ntnvdan4mi.LoggedData
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.pmbbvmnd0u.LoggedData
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.h0d5pw5l3d.LoggedData
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.gjule5o53k.LoggedData
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.hdjci4ngew.LoggedData
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.nzn2mnjcf5.LoggedData
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.hco40fajyi.LoggedData
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.p25wj4xuuk.LoggedData
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.d3azz5z2mq
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.nf3duvwzmk
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 2;
	
	  ;% rtDW.gm1dcsqrzm.PrevIndex
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% rtDW.a5dgjvoljo
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.luap051kiq
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.e0do2nutvy
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.cqqe4ackda
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.czecwii4jn
	  section.data(5).logicalSrcIdx = 16;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.fdafrlqdiy
	  section.data(6).logicalSrcIdx = 17;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.cepg00qrhs
	  section.data(7).logicalSrcIdx = 18;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.pzbp2jg2ny
	  section.data(8).logicalSrcIdx = 19;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.kxhtuldmhk
	  section.data(9).logicalSrcIdx = 20;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.gbrl2nobbn
	  section.data(10).logicalSrcIdx = 21;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
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


  targMap.checksum0 = 252174475;
  targMap.checksum1 = 3684857294;
  targMap.checksum2 = 833005927;
  targMap.checksum3 = 3066074947;

