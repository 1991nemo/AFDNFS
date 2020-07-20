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
      section.nData     = 190;
      section.data(190)  = dumData; %prealloc
      
	  ;% rtP.FlatEarthtoLLA_LL0
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.Doublet_T_start
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% rtP.Doublet_amp
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% rtP.DragCoefficient_cD0
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% rtP.LiftCoefficient_cL0
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% rtP.CompareToConstant_const
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% rtP.CompareToConstant_const_b0xas2jkq3
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% rtP.CompareToConstant_const_kmoxadnhb5
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% rtP.CompareToConstant_const_nifrvxypha
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 9;
	
	  ;% rtP.CompareToConstant_const_lrvr5wm4my
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 10;
	
	  ;% rtP.CompareToConstant_const_obwydhle4i
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 11;
	
	  ;% rtP.LiftCoefficient_meanchord
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 12;
	
	  ;% rtP.FlatEarthtoLLA_psi
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 13;
	
	  ;% rtP.Doublet_span
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 14;
	
	  ;% rtP.Bias_Bias
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 15;
	
	  ;% rtP.Gain_Gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 16;
	
	  ;% rtP.Bias1_Bias
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 17;
	
	  ;% rtP.Bias_Bias_egwxvvuqi5
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 18;
	
	  ;% rtP.Bias1_Bias_hhxbgizgvm
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 19;
	
	  ;% rtP.Bias_Bias_eiu2cdruu3
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 20;
	
	  ;% rtP.Bias1_Bias_hfpwrebp0l
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 21;
	
	  ;% rtP.Gain_Gain_mxsmwhuwrc
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 22;
	
	  ;% rtP.Gain7_Gain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 23;
	
	  ;% rtP.Gain1_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 24;
	
	  ;% rtP.Gain6_Gain
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 25;
	
	  ;% rtP.Gain2_Gain
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 26;
	
	  ;% rtP.Gain5_Gain
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 27;
	
	  ;% rtP.Gain3_Gain
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 28;
	
	  ;% rtP.Gain4_Gain
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 29;
	
	  ;% rtP.Gain2_Gain_ntnvl1cqpn
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 30;
	
	  ;% rtP.ChSign2_Gain
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 31;
	
	  ;% rtP.ChSign_Gain
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 32;
	
	  ;% rtP.ChSign1_Gain
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 33;
	
	  ;% rtP.ChSign2_Gain_blrwynkzlu
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 34;
	
	  ;% rtP.Limitaltitudetotroposhere_UpperSat
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 35;
	
	  ;% rtP.Limitaltitudetotroposhere_LowerSat
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 36;
	
	  ;% rtP.LapseRate_Gain
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 37;
	
	  ;% rtP.uT0_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 38;
	
	  ;% rtP.rho0_Gain
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 39;
	
	  ;% rtP.LimitaltitudetoStratosphere_UpperSat
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 40;
	
	  ;% rtP.LimitaltitudetoStratosphere_LowerSat
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 41;
	
	  ;% rtP.gR_Gain
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 42;
	
	  ;% rtP.Gain_Gain_d31dqzkeif
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 43;
	
	  ;% rtP.cLalpha_Gain
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 44;
	
	  ;% rtP.Step_Y0
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 45;
	
	  ;% rtP.Step1_Y0
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 46;
	
	  ;% rtP.Step2_Y0
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 47;
	
	  ;% rtP.Step3_Y0
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 48;
	
	  ;% rtP.FromWs_Time0
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 49;
	
	  ;% rtP.FromWs_Data0
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 62;
	
	  ;% rtP.FromWs_Time0_elms23aku5
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 75;
	
	  ;% rtP.FromWs_Data0_epwwwxrf5p
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 84;
	
	  ;% rtP.FromWs_Time0_dbgr3faoo4
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 93;
	
	  ;% rtP.FromWs_Data0_gk1j2xmtdn
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 106;
	
	  ;% rtP.FromWs_Time0_l0kcnhlhti
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 119;
	
	  ;% rtP.FromWs_Data0_pabez3hm0f
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 132;
	
	  ;% rtP.LongLQR_Gain
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 145;
	
	  ;% rtP.Gain_Gain_is0it0xd34
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 149;
	
	  ;% rtP.Saturation1_UpperSat
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 150;
	
	  ;% rtP.Saturation1_LowerSat
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 151;
	
	  ;% rtP.LatLQR_Gain
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 152;
	
	  ;% rtP.Gain1_Gain_mfxdzqt1sa
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 162;
	
	  ;% rtP.Saturation2_UpperSat
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 163;
	
	  ;% rtP.Saturation2_LowerSat
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 164;
	
	  ;% rtP.cLdelta_e_Gain
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 165;
	
	  ;% rtP.cLdelta_f_Gain
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 166;
	
	  ;% rtP.TransferFcn_A
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 167;
	
	  ;% rtP.TransferFcn_C
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 168;
	
	  ;% rtP.cLalphadot_Gain
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 169;
	
	  ;% rtP.cLq_Gain
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 170;
	
	  ;% rtP.u_Gain
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 171;
	
	  ;% rtP.gammaR_Gain
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 172;
	
	  ;% rtP.CLM_Gain
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 173;
	
	  ;% rtP.InducedDrag_Gain
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 174;
	
	  ;% rtP.cDalpha_Gain
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 175;
	
	  ;% rtP.cDdelta_f_Gain
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 176;
	
	  ;% rtP.cDdelta_e_Gain
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 177;
	
	  ;% rtP.cDdelta_a_Gain
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 178;
	
	  ;% rtP.cDdelta_r_Gain
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 179;
	
	  ;% rtP.cDM_Gain
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 180;
	
	  ;% rtP.ChSign_Gain_pd02wcxouh
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 181;
	
	  ;% rtP.cYbeta_Gain
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 182;
	
	  ;% rtP.cYdelta_a_Gain
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 183;
	
	  ;% rtP.cYdelta_r_Gain
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 184;
	
	  ;% rtP.cYp_Gain
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 185;
	
	  ;% rtP.cYr_Gain
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 186;
	
	  ;% rtP.u_Gain_pb5qen5bq2
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 187;
	
	  ;% rtP.ChSign1_Gain_jgqy0alfoa
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 188;
	
	  ;% rtP.FromWs_Time0_i2ajdr5pty
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 189;
	
	  ;% rtP.FromWs_Data0_hempjedlcs
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 195;
	
	  ;% rtP.Gain1_Gain_jlinvxtcyq
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 201;
	
	  ;% rtP.Gain_Gain_fldlnfjp4b
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 202;
	
	  ;% rtP.ChSign_Gain_jrexwz533r
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 203;
	
	  ;% rtP.ChSign1_Gain_p1dv1gzhg0
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 204;
	
	  ;% rtP.ChSign2_Gain_mg4y2ieuqq
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 205;
	
	  ;% rtP.clbeta_Gain
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 206;
	
	  ;% rtP.cldelta_a_Gain
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 207;
	
	  ;% rtP.cldelta_r_Gain
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 208;
	
	  ;% rtP.clp_Gain
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 209;
	
	  ;% rtP.clr_Gain
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 210;
	
	  ;% rtP.u_Gain_dzcqhyfoug
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 211;
	
	  ;% rtP.cmalpha_Gain
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 212;
	
	  ;% rtP.cmdelta_f_Gain
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 213;
	
	  ;% rtP.cmdelta_e_Gain
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 214;
	
	  ;% rtP.cmalphadot_Gain
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 215;
	
	  ;% rtP.cmq_Gain
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 216;
	
	  ;% rtP.u_Gain_kpl0cbpinj
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 217;
	
	  ;% rtP.cmM_Gain
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 218;
	
	  ;% rtP.cnbeta_Gain
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 219;
	
	  ;% rtP.cndelta_a_Gain
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 220;
	
	  ;% rtP.cndelta_r_Gain
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 221;
	
	  ;% rtP.cnp_Gain
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 222;
	
	  ;% rtP.cnr_Gain
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 223;
	
	  ;% rtP.u_Gain_p0db5lqo0p
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 224;
	
	  ;% rtP.Gain1_Gain_b1hf4hkty0
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 225;
	
	  ;% rtP.Gain_Gain_dqhhuexjt5
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 226;
	
	  ;% rtP.Gain5_Gain_lm3oic4sdo
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 227;
	
	  ;% rtP.Gain3_Gain_hjbg4mtw5c
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 228;
	
	  ;% rtP.Gain4_Gain_l0vaw0ty4p
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 231;
	
	  ;% rtP.TransferFcn1_A
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 234;
	
	  ;% rtP.TransferFcn1_C
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 235;
	
	  ;% rtP.Constant_Value
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 236;
	
	  ;% rtP.AltitudeofTroposphere_Value
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 237;
	
	  ;% rtP.SeaLevelTemperature_Value
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 238;
	
	  ;% rtP.gLR_Value
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 239;
	
	  ;% rtP.Zero_Value
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 240;
	
	  ;% rtP.WingArea_Value
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 241;
	
	  ;% rtP.Wingspan_Value
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 242;
	
	  ;% rtP.Zero_Value_dhaiu1n4hb
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 243;
	
	  ;% rtP.Wingarea_Value
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 244;
	
	  ;% rtP.Wingchord_Value
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 245;
	
	  ;% rtP.Wingspan_Value_cr0bafp5uf
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 246;
	
	  ;% rtP.Wingspan2_Value
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 247;
	
	  ;% rtP.Cm0_Value
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 248;
	
	  ;% rtP.Wingchord_Value_emuwkezyaz
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 249;
	
	  ;% rtP.Wingspan_Value_drrojpryp4
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 250;
	
	  ;% rtP.Wingspan_Value_erx3lkovhx
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 251;
	
	  ;% rtP.Constant_Value_o10wbquf15
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 252;
	
	  ;% rtP.Constant1_Value
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 253;
	
	  ;% rtP.Constant2_Value
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 254;
	
	  ;% rtP.Constant2_Value_aoptzpbs55
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 255;
	
	  ;% rtP.Constant_Value_bx2r5flqh4
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 256;
	
	  ;% rtP.Constant1_Value_folsuaqk2w
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 257;
	
	  ;% rtP.Bias_Bias_lfg1tbgilu
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 258;
	
	  ;% rtP.Constant2_Value_muoeisyhao
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 259;
	
	  ;% rtP.Bias1_Bias_dxmrixcsmx
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 260;
	
	  ;% rtP.Bias_Bias_f2s41qt1rc
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 261;
	
	  ;% rtP.Gain_Gain_p3bohr0orw
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 262;
	
	  ;% rtP.Bias1_Bias_h3sn5uls4z
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 263;
	
	  ;% rtP.Bias_Bias_d5zpfez5uz
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 264;
	
	  ;% rtP.Constant2_Value_ir4n4t0fex
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 265;
	
	  ;% rtP.Bias1_Bias_ewxdzezg00
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 266;
	
	  ;% rtP.Constant_Value_lljga3nj5j
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 267;
	
	  ;% rtP.Constant1_Value_d1hfa5vt1i
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 268;
	
	  ;% rtP.Constant2_Value_pkofftudxg
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 269;
	
	  ;% rtP.Constant3_Value
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 270;
	
	  ;% rtP.Constant_Value_mibaoj2rgl
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 271;
	
	  ;% rtP.Constant_Value_enfqz0alpl
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 272;
	
	  ;% rtP.Constant_Value_mjz5zpttx1
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 273;
	
	  ;% rtP.f_Value
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 274;
	
	  ;% rtP.RefAlt_Value
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 275;
	
	  ;% rtP.TrimThrust1_Value
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 276;
	
	  ;% rtP.TrimThrust2_Value
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 277;
	
	  ;% rtP.TrimThrust3_Value
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 278;
	
	  ;% rtP.Throttle_Gain
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 279;
	
	  ;% rtP.TrimThrust4_Value
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 280;
	
	  ;% rtP.TrimThrust5_Value
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 281;
	
	  ;% rtP.mass_Value
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 284;
	
	  ;% rtP.TrimThrust5_Value_pghqg4ahuq
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 285;
	
	  ;% rtP.Constant_Value_ki5yoscsu1
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 288;
	
	  ;% rtP.Constant1_Value_old4tikkcg
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 289;
	
	  ;% rtP.Constant2_Value_lh0btpjb3l
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 290;
	
	  ;% rtP.Constant3_Value_f1k1adieba
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 299;
	
	  ;% rtP.Constant4_Value
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 308;
	
	  ;% rtP.Constant6_Value
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 311;
	
	  ;% rtP.Constant7_Value
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 314;
	
	  ;% rtP.Constant8_Value
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 317;
	
	  ;% rtP.Constant2_Value_eiuvnldjii
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 320;
	
	  ;% rtP.Constant_Value_ldaynjj304
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 324;
	
	  ;% rtP.Constant1_Value_aja1fvk5dn
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 325;
	
	  ;% rtP.Constant2_Value_gm0og1aigu
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 327;
	
	  ;% rtP.dF_Value
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 328;
	
	  ;% rtP.ControlledPlant_Value
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 329;
	
	  ;% rtP.Constant_Value_iltbyzakku
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 333;
	
	  ;% rtP.Constant2_Value_bvlfok2r5u
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 336;
	
	  ;% rtP.FreePlant_Value
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 337;
	
	  ;% rtP.Constant1_Value_of0klte1gr
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 341;
	
	  ;% rtP.Constant2_Value_ol34lh25j4
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 342;
	
	  ;% rtP.Constant3_Value_ey1nyz4g22
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 343;
	
	  ;% rtP.Constant4_Value_iwlbmt1pf3
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 344;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% rtP.ManualSwitch1_CurrentSetting
	  section.data(1).logicalSrcIdx = 190;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.ManualSwitch_CurrentSetting
	  section.data(2).logicalSrcIdx = 191;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.ManualSwitch2_CurrentSetting
	  section.data(3).logicalSrcIdx = 192;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.ManualSwitch1_CurrentSetting_g2n2m14h1o
	  section.data(4).logicalSrcIdx = 193;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.ManualSwitch_CurrentSetting_mbegp1wenu
	  section.data(5).logicalSrcIdx = 194;
	  section.data(5).dtTransOffset = 4;
	
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
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 58;
      section.data(58)  = dumData; %prealloc
      
	  ;% rtB.mbeszndpzw
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.pxlcyjc0py
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% rtB.ddodrccvry
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% rtB.prll55li14
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% rtB.jxiqnugoaw
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 10;
	
	  ;% rtB.hjeoespy50
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 11;
	
	  ;% rtB.lf41qcir2i
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% rtB.g2bzvajzvm
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 13;
	
	  ;% rtB.nxlyj2r2ke
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 16;
	
	  ;% rtB.igulonupg4
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 17;
	
	  ;% rtB.iluz41jmye
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 18;
	
	  ;% rtB.lbzm4w3kvc
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 20;
	
	  ;% rtB.odqjhpytke
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 24;
	
	  ;% rtB.n51upk5du5
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 25;
	
	  ;% rtB.b4lvv4thsq
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 26;
	
	  ;% rtB.j4qce2ejgk
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 27;
	
	  ;% rtB.j2ppwxwj2v
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 28;
	
	  ;% rtB.puqzbadmna
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 29;
	
	  ;% rtB.p43ilaklx2
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 31;
	
	  ;% rtB.ebdsowrcxw
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 32;
	
	  ;% rtB.aa5dhjvrml
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 33;
	
	  ;% rtB.fl2tbgohhi
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 34;
	
	  ;% rtB.kf1oc12ha5
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 35;
	
	  ;% rtB.ltejiu1rdi
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 36;
	
	  ;% rtB.nc2kd2edsn
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 37;
	
	  ;% rtB.paumsm4ucv
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 38;
	
	  ;% rtB.pd3h1ffkcz
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 41;
	
	  ;% rtB.aiijml5ggp
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 44;
	
	  ;% rtB.mlb2v0rqr4
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 45;
	
	  ;% rtB.mmcuu43erm
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 46;
	
	  ;% rtB.babk200cg1
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 47;
	
	  ;% rtB.eimam0aysg
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 48;
	
	  ;% rtB.n4ytkvk2rz
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 49;
	
	  ;% rtB.hc3hgdwtyb
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 50;
	
	  ;% rtB.axza31sfxm
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 53;
	
	  ;% rtB.ej5pw05q3j
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 56;
	
	  ;% rtB.hhdivriu54
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 59;
	
	  ;% rtB.nco05nrykr
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 62;
	
	  ;% rtB.l2let5yzu1
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 65;
	
	  ;% rtB.bt44u1ruqs
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 68;
	
	  ;% rtB.ewosjguuu0
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 71;
	
	  ;% rtB.iexmvyr4r4
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 74;
	
	  ;% rtB.gel1pzm210
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 77;
	
	  ;% rtB.l3nhcgjbby
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 78;
	
	  ;% rtB.obrryzou3p
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 79;
	
	  ;% rtB.l4k2a5bsh4
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 80;
	
	  ;% rtB.kzv3jtixuu
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 81;
	
	  ;% rtB.hcthdqledv
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 82;
	
	  ;% rtB.n5jin1c2zm
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 83;
	
	  ;% rtB.ladmdwvset
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 84;
	
	  ;% rtB.fqj3t5j0hs
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 85;
	
	  ;% rtB.gor1ljyslz
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 86;
	
	  ;% rtB.bh40mgxfug
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 89;
	
	  ;% rtB.ft1rv4ttnm
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 90;
	
	  ;% rtB.hbmslxdafy
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 93;
	
	  ;% rtB.lnbo3dn5b5
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 96;
	
	  ;% rtB.mai2btwwwy
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 99;
	
	  ;% rtB.dorju0mbfg
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 102;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtB.ar551zz3kn
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.ku1qygrkrl
	  section.data(2).logicalSrcIdx = 59;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.ao5xxbupqa
	  section.data(3).logicalSrcIdx = 60;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
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
    sectIdxOffset = 2;
    
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
      section.nData     = 29;
      section.data(29)  = dumData; %prealloc
      
	  ;% rtDW.ncc32vf3v1.LoggedData
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.d0d4erxb4a.LoggedData
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.nyrbrzpro5.TimePtr
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.knfsqkbog3.TimePtr
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.k2h3rugqu1.TimePtr
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.hcmwiu4oc2.TimePtr
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.ezztmokhxt.TimePtr
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.bz2cs2h00t.LoggedData
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.ivp2ovxafm.LoggedData
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.bv4ffxq4cc.LoggedData
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.ayqwng4oox.LoggedData
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.harm20pwft.LoggedData
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDW.l0rvcjwiw5.LoggedData
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDW.id40jhylbg.LoggedData
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDW.bcymmb43pv.LoggedData
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtDW.fuuads50cc.LoggedData
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtDW.bh30qlhvht.LoggedData
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtDW.f5t4pm1vqz.LoggedData
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtDW.etvjiflaud.LoggedData
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtDW.m425ywdp4l.LoggedData
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtDW.f0ngxdtb50.LoggedData
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtDW.gierlz4kga.LoggedData
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtDW.jmgxordfxn.LoggedData
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtDW.juhedu4p0x.LoggedData
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtDW.btibqafi5k.LoggedData
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtDW.bsc5lo3qxl.LoggedData
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtDW.e4fzd23hst.LoggedData
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtDW.ewjd54ti05.LoggedData
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtDW.h14pe03ska.LoggedData
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 36;
      section.data(36)  = dumData; %prealloc
      
	  ;% rtDW.j5skdyoj5i
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.hwhk0plcbm
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.dgdkommmsd
	  section.data(3).logicalSrcIdx = 31;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.bn4dbem3va
	  section.data(4).logicalSrcIdx = 32;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.kwtny14ets
	  section.data(5).logicalSrcIdx = 33;
	  section.data(5).dtTransOffset = 7;
	
	  ;% rtDW.kue5d1kul0.PrevIndex
	  section.data(6).logicalSrcIdx = 34;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtDW.exkkab2tvc.PrevIndex
	  section.data(7).logicalSrcIdx = 35;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtDW.c2y55kstcc
	  section.data(8).logicalSrcIdx = 36;
	  section.data(8).dtTransOffset = 10;
	
	  ;% rtDW.bfzneoincq
	  section.data(9).logicalSrcIdx = 37;
	  section.data(9).dtTransOffset = 14;
	
	  ;% rtDW.m2zkbzyhlz.PrevIndex
	  section.data(10).logicalSrcIdx = 38;
	  section.data(10).dtTransOffset = 15;
	
	  ;% rtDW.lgjhv10zvc
	  section.data(11).logicalSrcIdx = 39;
	  section.data(11).dtTransOffset = 16;
	
	  ;% rtDW.aivemugqf1
	  section.data(12).logicalSrcIdx = 40;
	  section.data(12).dtTransOffset = 20;
	
	  ;% rtDW.jqiesixgdv.PrevIndex
	  section.data(13).logicalSrcIdx = 41;
	  section.data(13).dtTransOffset = 21;
	
	  ;% rtDW.j4k0h2foay
	  section.data(14).logicalSrcIdx = 42;
	  section.data(14).dtTransOffset = 22;
	
	  ;% rtDW.auwndvyfpq
	  section.data(15).logicalSrcIdx = 43;
	  section.data(15).dtTransOffset = 23;
	
	  ;% rtDW.hqdpuh5bh4
	  section.data(16).logicalSrcIdx = 44;
	  section.data(16).dtTransOffset = 25;
	
	  ;% rtDW.dfcv1ogrid.PrevIndex
	  section.data(17).logicalSrcIdx = 45;
	  section.data(17).dtTransOffset = 26;
	
	  ;% rtDW.kv4lnrjne2
	  section.data(18).logicalSrcIdx = 46;
	  section.data(18).dtTransOffset = 27;
	
	  ;% rtDW.hgmvbytvsp
	  section.data(19).logicalSrcIdx = 47;
	  section.data(19).dtTransOffset = 28;
	
	  ;% rtDW.fb0tpkibfq
	  section.data(20).logicalSrcIdx = 48;
	  section.data(20).dtTransOffset = 29;
	
	  ;% rtDW.nslzihk2f5
	  section.data(21).logicalSrcIdx = 49;
	  section.data(21).dtTransOffset = 30;
	
	  ;% rtDW.hveldcssno
	  section.data(22).logicalSrcIdx = 50;
	  section.data(22).dtTransOffset = 31;
	
	  ;% rtDW.ef2fks3n4u
	  section.data(23).logicalSrcIdx = 51;
	  section.data(23).dtTransOffset = 32;
	
	  ;% rtDW.o3c1xdpheq
	  section.data(24).logicalSrcIdx = 52;
	  section.data(24).dtTransOffset = 33;
	
	  ;% rtDW.amfzu1el4q
	  section.data(25).logicalSrcIdx = 53;
	  section.data(25).dtTransOffset = 34;
	
	  ;% rtDW.gdmux55hjy
	  section.data(26).logicalSrcIdx = 54;
	  section.data(26).dtTransOffset = 35;
	
	  ;% rtDW.csi2mijlzp
	  section.data(27).logicalSrcIdx = 55;
	  section.data(27).dtTransOffset = 36;
	
	  ;% rtDW.h43rirlooy
	  section.data(28).logicalSrcIdx = 56;
	  section.data(28).dtTransOffset = 38;
	
	  ;% rtDW.jk5xksjzsk
	  section.data(29).logicalSrcIdx = 57;
	  section.data(29).dtTransOffset = 39;
	
	  ;% rtDW.eb0yxld54a
	  section.data(30).logicalSrcIdx = 58;
	  section.data(30).dtTransOffset = 40;
	
	  ;% rtDW.d4kppgermp
	  section.data(31).logicalSrcIdx = 59;
	  section.data(31).dtTransOffset = 41;
	
	  ;% rtDW.awptayczte
	  section.data(32).logicalSrcIdx = 60;
	  section.data(32).dtTransOffset = 42;
	
	  ;% rtDW.chwk0ea5er
	  section.data(33).logicalSrcIdx = 61;
	  section.data(33).dtTransOffset = 43;
	
	  ;% rtDW.hmcvrdlbiw
	  section.data(34).logicalSrcIdx = 62;
	  section.data(34).dtTransOffset = 44;
	
	  ;% rtDW.mujtalxvpm
	  section.data(35).logicalSrcIdx = 63;
	  section.data(35).dtTransOffset = 45;
	
	  ;% rtDW.kxe4uaswic
	  section.data(36).logicalSrcIdx = 64;
	  section.data(36).dtTransOffset = 46;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% rtDW.i3ztellsjl
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.kdajnepqa5
	  section.data(2).logicalSrcIdx = 66;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.euxjrceybc
	  section.data(3).logicalSrcIdx = 67;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.lq4r04u54d
	  section.data(4).logicalSrcIdx = 68;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.jro3w2jetk
	  section.data(5).logicalSrcIdx = 69;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.fciwvikpdr
	  section.data(6).logicalSrcIdx = 70;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.n5ngktfrhq
	  section.data(7).logicalSrcIdx = 71;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.dxc22zb0w3
	  section.data(8).logicalSrcIdx = 72;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.mqarvij1wr
	  section.data(9).logicalSrcIdx = 73;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.dkeirtfvst
	  section.data(10).logicalSrcIdx = 74;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.arnvx1x5wb
	  section.data(11).logicalSrcIdx = 75;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.f5ilhbx002
	  section.data(12).logicalSrcIdx = 76;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.ligunf0r1k
	  section.data(1).logicalSrcIdx = 77;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.mug4q33r34
	  section.data(2).logicalSrcIdx = 78;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.bzoc2ge3pm
	  section.data(3).logicalSrcIdx = 79;
	  section.data(3).dtTransOffset = 2;
	
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


  targMap.checksum0 = 4196730302;
  targMap.checksum1 = 151385502;
  targMap.checksum2 = 2760859041;
  targMap.checksum3 = 3234198081;

