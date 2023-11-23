
Load Bahama  Mamas: (must teleport in)
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -1388.0013427734375, -618.419677734375, 30.819599151611328), false);
            Function.Call(Hash.REQUEST_IPL, "v_bahama");
Unload Bahama  Mamas:
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -1388.0013427734375, -618.419677734375, 30.819599151611328), true);
            Function.Call(Hash.REMOVE_IPL, "v_bahama");

Load Chopshop:
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 479.0567932128906f, -1316.8253173828125f, 28.2038f), false);
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 479.0567932128906f, -1316.8253173828125f, 28.2038f), false);
            Function.Call(Hash.REQUEST_IPL, "v_chopshop");
            Function.Call(Hash.UNPIN_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 479.0567932128906f, -1316.8253173828125f, 28.2038f));
            Function.Call(Hash._DOOR_CONTROL, -664582244, 482.8112f, -1311.953f, 29.35057f, true, 0.0f, 0.0f, -1.0f);
            Function.Call(Hash._DOOR_CONTROL, -190780785, 484.5652f, -1315.574f, 30.20331f, true, 0.0f, 0.0f, 0.0f);
Unload Chopshop:
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 479.0567932128906f, -1316.8253173828125f, 28.2038f), true);
            Function.Call(Hash.REMOVE_IPL, "v_chopshop");

Load Cluckin Bell:
            Function.Call(Hash.REQUEST_IPL, "CS1_02_cf_onmission1");
            Function.Call(Hash.REQUEST_IPL, "CS1_02_cf_onmission2");
            Function.Call(Hash.REQUEST_IPL, "CS1_02_cf_onmission3");
            Function.Call(Hash.REQUEST_IPL, "CS1_02_cf_onmission4");
            Function.Call(Hash.REMOVE_IPL, "CS1_02_cf_offmission");
Unload Cluckin Bell:
            Function.Call(Hash.REMOVE_IPL, "CS1_02_cf_onmission1");
            Function.Call(Hash.REMOVE_IPL, "CS1_02_cf_onmission2");
            Function.Call(Hash.REMOVE_IPL, "CS1_02_cf_onmission3");
            Function.Call(Hash.REMOVE_IPL, "CS1_02_cf_onmission4");
            Function.Call(Hash.REQUEST_IPL, "CS1_02_cf_offmission");

Load Comedy club: (spilt sides) no collision for walls  (must teleport in)
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -447.4833068847656, 280.3197021484375, 77.52149963378906), false);
            Function.Call(Hash.REQUEST_IPL, "v_comedy");
Unload Comedy club: (spilt sides)
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -447.4833068847656, 280.3197021484375, 77.52149963378906), true);
            Function.Call(Hash.REMOVE_IPL, "v_comedy");

Load Fame or Shame Stadium:
            Function.Call(Hash.REMOVE_IPL, "sp1_10_fake_interior");
            Function.Call(Hash.REMOVE_IPL, "sp1_10_fake_interior_lod");
            Function.Call(Hash.REQUEST_IPL, "sp1_10_real_interior");
            Function.Call(Hash.REQUEST_IPL, "sp1_10_real_interior_lod");
Unload Fame or Shame stadium:
            Function.Call(Hash.REMOVE_IPL, "sp1_10_real_interior");
            Function.Call(Hash.REMOVE_IPL, "sp1_10_real_interior_lod");
            Function.Call(Hash.REQUEST_IPL, "sp1_10_fake_interior");
            Function.Call(Hash.REQUEST_IPL, "sp1_10_fake_interior_lod");

Load FIB Lobby:
            Function.Call(Hash.REQUEST_IPL, "FIBlobby");
            Function.Call(Hash.REMOVE_IPL, "FIBlobbyfake");
            Function.Call(Hash._DOOR_CONTROL, -1517873911, 106.3793f, -742.6982f, 46.51962f, false, 0.0f, 0.0f, 0.0f);
            Function.Call(Hash._DOOR_CONTROL, -90456267, 105.7607f, -746.646f, 46.18266f, false, 0.0f, 0.0f, 0.0f);
Unload FIB Lobby:
            Function.Call(Hash.REQUEST_IPL, "FIBlobbyfake");
            Function.Call(Hash.REMOVE_IPL, "FIBlobby");
            Function.Call(Hash._DOOR_CONTROL, -1517873911, 106.3793f, -742.6982f, 46.51962f, true, 0.0f, 0.0f, 0.0f);
            Function.Call(Hash._DOOR_CONTROL, -90456267, 105.7607f, -746.646f, 46.18266f, true, 0.0f, 0.0f, 0.0f);

Load Foundry:
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 1087.1951904296875, -1988.4449462890625, 28.649), false);
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 1087.1951904296875, -1988.4449462890625, 28.649), false);
            Function.Call(Hash.REQUEST_IPL, "v_foundry");
            Function.Call(Hash._DOOR_CONTROL, -1428622127, 1083.547f, -1975.435f, 31.62222f, true, 0.0f, 0.0f, -1.0f);
            Function.Call(Hash._DOOR_CONTROL, -1428622127, 1085.307f, -2018.561f, 41.62894f, true, 0.0f, 0.0f, 1.0f);
Unload Foundry:
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 1087.1951904296875, -1988.4449462890625, 28.649), true);
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 1087.1951904296875, -1988.4449462890625, 28.649), true);
            Function.Call(Hash.REMOVE_IPL, "v_foundry");

Load Floyd's house:
            Function.Call(Hash.REMOVE_IPL, "vb_30_crimetape");
            Function.Call(Hash._DOOR_CONTROL, -607040053, -1149.709f, -1521.088f, 10.78267f, false, 0.0f, 0.0f, 0.0f);

Load Epsilon:
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 245.15640258789062, 370.21099853515625, 104.73819732666016), false);
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 245.15640258789062, 370.21099853515625, 104.73819732666016), false);
            Function.Call(Hash.REQUEST_IPL, "v_epsilonism");
            Function.Call(Hash._DOOR_CONTROL, -1230442770, 241.3621f, 361.0471f, 105.8883f, false, 0.0f, 0.0f, 0.0f);
Unoad Epsilon:
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 245.15640258789062, 370.21099853515625, 104.73819732666016), true);
            Function.Call(Hash.REMOVE_IPL, "v_epsilonism");
            Function.Call(Hash._DOOR_CONTROL, -1230442770, 241.3621f, 361.0471f, 105.8883f, true, 0.0f, 0.0f, 0.0f);

Load Epsilon:
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 245.15640258789062, 370.21099853515625, 104.73819732666016), false);
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 245.15640258789062, 370.21099853515625, 104.73819732666016), false);
            Function.Call(Hash._0x2CA429C029CCF247, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 245.15640258789062, 370.21099853515625, 104.73819732666016));
            Function.Call(Hash.UNPIN_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 245.15640258789062, 370.21099853515625, 104.73819732666016));
            Function.Call(Hash._DOOR_CONTROL, -1230442770, 241.3621f, 361.0471f, 105.8883f, false, 0.0f, 0.0f, 0.0f);
Unload Epsilon:
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 245.15640258789062, 370.21099853515625, 104.73819732666016), true);
            Function.Call(Hash._DOOR_CONTROL, -1230442770, 241.3621f, 361.0471f, 105.8883f, true, 0.0f, 0.0f, 0.0f);

Load Hospital normal:
            Function.Call(Hash.REMOVE_IPL, "RC12B_Destroyed");
            Function.Call(Hash.REMOVE_IPL, "RC12B_HospitalInterior");
            Function.Call(Hash.REMOVE_IPL, "RC12B_Default");
            Function.Call(Hash.REMOVE_IPL, "RC12B_Fixed");
            Function.Call(Hash.REQUEST_IPL, "RC12B_Default");//state 1 normal
Load Hospital Destroyed:
            Function.Call(Hash.REMOVE_IPL, "RC12B_Destroyed");
            Function.Call(Hash.REMOVE_IPL, "RC12B_HospitalInterior");
            Function.Call(Hash.REMOVE_IPL, "RC12B_Default");
            Function.Call(Hash.REMOVE_IPL, "RC12B_Fixed");
            Function.Call(Hash.REQUEST_IPL, "RC12B_Destroyed");//state 3 1of2
            Function.Call(Hash.REQUEST_IPL, "RC12B_HospitalInterior");//state 3 2of2 Destroyed Interior
Load Hospital boarded up:
            Function.Call(Hash.REMOVE_IPL, "RC12B_Destroyed");
            Function.Call(Hash.REMOVE_IPL, "RC12B_HospitalInterior");
            Function.Call(Hash.REMOVE_IPL, "RC12B_Default");
            Function.Call(Hash.REMOVE_IPL, "RC12B_Fixed");
            Function.Call(Hash.REQUEST_IPL, "RC12B_Fixed");//state 2 boarded up

Janitor
            Function.Call(Hash.REQUEST_IPL, "v_janitor");
            Function.Call(Hash._DOOR_CONTROL, 486670049, -107.5373f, -9.018099f, 70.67085f, false, 0.0f, 0.0f, 0.0f);

Jewel store
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -630.4, -236.7, 40.0), false);
            Function.Call(Hash.UNPIN_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -630.4, -236.7, 40.0));
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -630.4, -236.7, 40.0), false);
            Function.Call(Hash.REQUEST_IPL, "post_hiest_unload");
            Function.Call(Hash.REMOVE_IPL, "jewel2fake");
            Function.Call(Hash.REMOVE_IPL, "bh1_16_refurb");
            Function.Call(Hash._DOOR_CONTROL, 9467943, -630.4265f, -238.4375f, 38.20653f, true, 0.0f, 0.0f, 1.0f);
            Function.Call(Hash._DOOR_CONTROL, 1425919976, -631.9554f, -236.3333f, 38.20653f, true, 0.0f, 0.0f, -1.0f);

Lab
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 3522.84521484375, 3707.96533203125, 19.9918), false);
            Function.Call(Hash.REQUEST_IPL, "v_lab");
            Function.Call(Hash._DOOR_CONTROL, -1081024910, 3620.843f, 3751.527f, 27.69009f, false, 0.0f, 0.0f, -1.0f);
            Function.Call(Hash._DOOR_CONTROL, -1081024910, 3627.713f, 3746.716f, 27.69009f, false, 0.0f, 0.0f, -1.0f);
            elevator coords 3540.65f, 3675.77f, 28.12f
            elevator2 coords 3540.65f, 3675.77f, 20.12f

Load LifeInvader:
            Function.Call(Hash.REQUEST_IPL, "facelobby");  // lifeinvader
            Function.Call(Hash.REMOVE_IPL, "facelobbyfake");
            Function.Call(Hash._DOOR_CONTROL, -340230128, -1042.518, -240.6915, 38.11796, true, 0.0f, 0.0f, -1.0f);
Unoad LifeInvader:
            Function.Call(Hash.REMOVE_IPL, "facelobby");  // lifeinvader
            Function.Call(Hash.REQUEST_IPL, "facelobbyfake");
            Function.Call(Hash._DOOR_CONTROL, -340230128, -1042.518, -240.6915, 38.11796, true, 0.0f, 0.0f, 0.0f);

Load Lesters house:
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 1274.933837890625, -1714.7255859375, 53.77149963378906), false);
            Function.Call(Hash.REQUEST_IPL, "v_lesters");
            Function.Call(Hash._DOOR_CONTROL, 1145337974, 1273.816f, -1720.697f, 54.92143f, false, 0.0f, 0.0f, 0.0f);
Unload Lesters house:
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 1274.933837890625, -1714.7255859375, 53.77149963378906), false);
            Function.Call(Hash.REMOVE_IPL, "v_lesters");
            Function.Call(Hash._DOOR_CONTROL, 1145337974, 1273.816f, -1720.697f, 54.92143f, true, 0.0f, 0.0f, 0.0f);

Load Lesters Factory:
            Function.Call(Hash.REMOVE_IPL, "id2_14_during_door");
            Function.Call(Hash.REMOVE_IPL, "id2_14_during1");
            Function.Call(Hash.REMOVE_IPL, "id2_14_during2");
            Function.Call(Hash.REMOVE_IPL, "id2_14_on_fire");
            Function.Call(Hash.REMOVE_IPL, "id2_14_post_no_int");
            Function.Call(Hash.REMOVE_IPL, "id2_14_pre_no_int");
            Function.Call(Hash.REMOVE_IPL, "id2_14_during_door");
            Function.Call(Hash.REQUEST_IPL, "id2_14_during1");
            Function.Call(Hash._DOOR_CONTROL, 826072862, 717.0f, -975.0f, 25.0f, false, 0.0f, 0.0f, 0.0f);
            Function.Call(Hash._DOOR_CONTROL, 763780711, 719.0f, -975.0f, 25.0f, false, 0.0f, 0.0f, 0.0f);
Unload Lesters Factory:
            Function.Call(Hash.REMOVE_IPL, "id2_14_during_door");
            Function.Call(Hash.REMOVE_IPL, "id2_14_during1");
            Function.Call(Hash.REMOVE_IPL, "id2_14_during2");
            Function.Call(Hash.REMOVE_IPL, "id2_14_on_fire");
            Function.Call(Hash.REMOVE_IPL, "id2_14_post_no_int");
            Function.Call(Hash.REMOVE_IPL, "id2_14_during_door");
            Function.Call(Hash.REQUEST_IPL, "id2_14_post_no_int"); 

Morgue  (must teleport in)
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -447.4833068847656, 280.3197021484375, 77.52149963378906), false);
            Function.Call(Hash.REQUEST_IPL, "Coroner_Int_on");
            Function.Call(Hash.REMOVE_IPL, "Coroner_Int_off");
            teleport coords 275.1f,  -1360.6f,  24.5f
            teleport2 coords 240.8f, -1379.5f, 33.74f

Load O'Neil Ranch:
            Function.Call(Hash.REMOVE_IPL, "farm_burnt");
            Function.Call(Hash.REMOVE_IPL, "farm_burnt_lod");
            Function.Call(Hash.REMOVE_IPL, "farm_burnt_props");
            Function.Call(Hash.REMOVE_IPL, "farmint_cap");
            Function.Call(Hash.REMOVE_IPL, "farmint_cap_lod");
            Function.Call(Hash.REQUEST_IPL, "farm");
            Function.Call(Hash.REQUEST_IPL, "farmint");
            Function.Call(Hash.REQUEST_IPL, "farm_lod");
            Function.Call(Hash.REQUEST_IPL, "farm_props");
Unload O'Neil Ranch:
            Function.Call(Hash.REMOVE_IPL, "farm");
            Function.Call(Hash.REMOVE_IPL, "farmint");
            Function.Call(Hash.REMOVE_IPL, "farm_lod");
            Function.Call(Hash.REMOVE_IPL, "farm_props");
            Function.Call(Hash.REQUEST_IPL, "farm_burnt");
            Function.Call(Hash.REQUEST_IPL, "farm_burnt_lod");
            Function.Call(Hash.REQUEST_IPL, "farm_burnt_props");
            Function.Call(Hash.REQUEST_IPL, "farmint_cap");
            Function.Call(Hash.REQUEST_IPL, "farmint_cap_lod");
         
Psycheoffice (must teleport in)
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -1906.7857666015625, -573.7576293945312, 19.077299118041992), false);
            Function.Call(Hash.REQUEST_IPL, "v_psycheoffice");

Load Ranch: (must teleport in)
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 1399.9730224609375, 1148.755859375, 113.33360290527344), false);
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 1399.9730224609375, 1148.755859375, 113.33360290527344), false);
            Function.Call(Hash._0x2CA429C029CCF247, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 1399.9730224609375, 1148.755859375, 113.33360290527344));
            Function.Call(Hash.UNPIN_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 1399.9730224609375, 1148.755859375, 113.33360290527344));
            //Function.Call(Hash._DOOR_CONTROL, 1504256620, 1395.92f, 1142.904f, 114.7902f, true, 0.0f, 0.0f, 1.0f);
            //Function.Call(Hash._DOOR_CONTROL, -52575179, 1390.666f, 1133.317f, 114.4808f, true, 0.0f, 0.0f, -1.0f);
Unload Ranch: (must teleport in)
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 1399.9730224609375, 1148.755859375, 113.33360290527344), true);

Load Rogers Salvage & Scrap: (doors will lock if you leave area)
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -598.6378784179688, -1608.3985595703125, 26.010799407958984), false);
            Function.Call(Hash.UNPIN_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -598.6378784179688, -1608.3985595703125, 26.010799407958984));
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -598.6378784179688, -1608.3985595703125, 26.010799407958984), false);
            Function.Call(Hash.REQUEST_IPL, "v_recycle");
            Function.Call(Hash._DOOR_CONTROL, 1099436502, -608.7289f, -1610.315f, 27.15894f, false, 0.0f, 0.0f, -1.0f);
            Function.Call(Hash._DOOR_CONTROL, -1627599682, -611.32f, -1610.089f, 27.15894f, false, 0.0f, 0.0f, 1.0f);
            Function.Call(Hash._DOOR_CONTROL, 1099436502, -592.9376f, -1631.577f, 27.15931f, false, 0.0f, 0.0f, -1.0f);
            Function.Call(Hash._DOOR_CONTROL, -1627599682, -592.7109f, -1628.986f, 27.15931f, false, 0.0f, 0.0f, 1.0f);
Unload Rogers Salvage & Scrap:
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -598.6378784179688, -1608.3985595703125, 26.010799407958984), true);
            Function.Call(Hash.REMOVE_IPL, "v_recycle");
            Function.Call(Hash._DOOR_CONTROL, 1099436502, -608.7289f, -1610.315f, 27.15894f, true, 0.0f, 0.0f, 0.0f);
            Function.Call(Hash._DOOR_CONTROL, -1627599682, -611.32f, -1610.089f, 27.15894f, true, 0.0f, 0.0f, 0.0f);
            Function.Call(Hash._DOOR_CONTROL, 1099436502, -592.9376f, -1631.577f, 27.15931f, true, 0.0f, 0.0f, 0.0f);
            Function.Call(Hash._DOOR_CONTROL, -1627599682, -592.7109f, -1628.986f, 27.15931f, true, 0.0f, 0.0f, 0.0f);

Load Rogers Salvage & Scrap: 2nd way
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -598.6378784179688, -1608.3985595703125, 26.010799407958984), false);
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -598.6378784179688, -1608.3985595703125, 26.010799407958984), false);
            Function.Call(Hash._0x2CA429C029CCF247, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -598.6378784179688, -1608.3985595703125, 26.010799407958984));
            Function.Call(Hash.UNPIN_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -598.6378784179688, -1608.3985595703125, 26.010799407958984));
            Function.Call(Hash._DOOR_CONTROL, 1099436502, -608.7289f, -1610.315f, 27.15894f, false, 0.0f, 0.0f, -1.0f);
            Function.Call(Hash._DOOR_CONTROL, -1627599682, -611.32f, -1610.089f, 27.15894f, false, 0.0f, 0.0f, 1.0f);
            Function.Call(Hash._DOOR_CONTROL, 1099436502, -592.9376f, -1631.577f, 27.15931f, false, 0.0f, 0.0f, -1.0f);
            Function.Call(Hash._DOOR_CONTROL, -1627599682, -592.7109f, -1628.986f, 27.15931f, false, 0.0f, 0.0f, 1.0f);
            
Load Sheriff Office paleto:
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -444.89068603515625, 6013.5869140625, 30.7164), false);
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -444.89068603515625, 6013.5869140625, 30.7164), false);
            Function.Call(Hash.REQUEST_IPL, "v_sheriff2");
            Function.Call(Hash.REMOVE_IPL, "cs1_16_sheriff_cap");
            Function.Call(Hash._DOOR_CONTROL, -1501157055, -444.4985f, 6017.06f, 31.86633f, false, 0.0f, 0.0f, 0.0f);
            Function.Call(Hash._DOOR_CONTROL, -1501157055, -442.66f, 6015.222f, 31.86633f, false, 0.0f, 0.0f, 0.0f);
Unload Sheriff Office paleto:
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -444.89068603515625, 6013.5869140625, 30.7164), true);
            Function.Call(Hash.REMOVE_IPL, "v_sheriff2");
            Function.Call(Hash.REQUEST_IPL, "cs1_16_sheriff_cap");
            Function.Call(Hash._DOOR_CONTROL, -1501157055, -444.4985f, 6017.06f, 31.86633f, true, 0.0f, 0.0f, 0.0f);
            Function.Call(Hash._DOOR_CONTROL, -1501157055, -442.66f, 6015.222f, 31.86633f, true, 0.0f, 0.0f, 0.0f);

Load Sheriff Office sandy shores:        
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 1854.2537841796875, 3686.738525390625, 33.2671012878418), false);
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 1854.2537841796875, 3686.738525390625, 33.2671012878418), false);
            Function.Call(Hash.REQUEST_IPL, "v_sheriff");
            Function.Call(Hash.REMOVE_IPL, "sheriff_cap");
            Function.Call(Hash._DOOR_CONTROL, -1765048490, 1855.685f, 3683.93f, 34.59282f, false, 0.0f, 0.0f, 0.0f);
Unload Sheriff Office sandy shores:        
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 1854.2537841796875, 3686.738525390625, 33.2671012878418), true);
            Function.Call(Hash.REMOVE_IPL, "v_sheriff");
            Function.Call(Hash.REQUEST_IPL, "sheriff_cap");
            Function.Call(Hash._DOOR_CONTROL, -1765048490, 1855.685f, 3683.93f, 34.59282f, true, 0.0f, 0.0f, 0.0f);

Load Simeons Showroom:
            Function.Call(Hash.REMOVE_IPL, "v_carshowroom");
            Function.Call(Hash.REMOVE_IPL, "shutter_open");
            Function.Call(Hash.REMOVE_IPL, "shutter_closed");
            Function.Call(Hash.REMOVE_IPL, "shr_int");
            Function.Call(Hash.REMOVE_IPL, "csr_inMission");
            Function.Call(Hash.REMOVE_IPL, "fakeint");
            Function.Call(Hash.REQUEST_IPL, "shr_int");
Unload Simeons Showroom:
            Function.Call(Hash.REMOVE_IPL, "v_carshowroom");
            Function.Call(Hash.REMOVE_IPL, "shutter_open");
            Function.Call(Hash.REMOVE_IPL, "shutter_closed");
            Function.Call(Hash.REMOVE_IPL, "shr_int");
            Function.Call(Hash.REMOVE_IPL, "csr_inMission");
            Function.Call(Hash.REMOVE_IPL, "fakeint");
            Function.Call(Hash.REQUEST_IPL, "fakeint");

Load Slaughter house: (doors will lock if you leave area)
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 982.2329711914062, -2160.381591796875, 28.4761), false);
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 982.2329711914062, -2160.381591796875, 28.4761), false);
            Function.Call(Hash.REQUEST_IPL, "v_abattoir");
            Function.Call(Hash._DOOR_CONTROL, -1468417022, 962.9084f, -2105.813f, 32.52716f, true, 0.0f, 0.0f, 1.0f);
            Function.Call(Hash._DOOR_CONTROL, 1755793225, 962.0066f, -2183.816f, 31.06194f, true, 0.0f, 0.0f, 1.0f);
            Function.Call(Hash.UNPIN_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 982.2329711914062, -2160.381591796875, 28.4761));
Unload Slaughter house:
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 982.2329711914062, -2160.381591796875, 28.4761), true);
            Function.Call(Hash._DOOR_CONTROL, -1468417022, 962.9084f, -2105.813f, 32.52716f, true, 0.0f, 0.0f, 0.0f);
            Function.Call(Hash._DOOR_CONTROL, 1755793225, 962.0066f, -2183.816f, 31.06194f, true, 0.0f, 0.0f, 0.0f);
            Function.Call(Hash.REMOVE_IPL, "v_abattoir");

Load Solomon's office:
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -1005.663208f, -478.3460998535156f, 49.0265f), false);
            Function.Call(Hash.REQUEST_IPL, "v_58_sol_office");

Load Stab city unburnt:
            Function.Call(Hash.REMOVE_IPL, "trailerparkA_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkA_grp2");
            Function.Call(Hash.REMOVE_IPL, "occl_trailerA_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkB_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkB_grp2");
            Function.Call(Hash.REMOVE_IPL, "occl_trailerB_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkC_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkC_grp2");
            Function.Call(Hash.REMOVE_IPL, "occl_trailerC_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkD_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkD_grp2");
            Function.Call(Hash.REMOVE_IPL, "occl_trailerD_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkE_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkE_grp2");
            Function.Call(Hash.REMOVE_IPL, "occl_trailerE_grp1");
            Function.Call(Hash.REMOVE_IPL, "des_methtrailer");
            Function.Call(Hash.REMOVE_IPL, "methtrailer_grp1");
            Function.Call(Hash.REMOVE_IPL, "methtrailer_grp2");
            Function.Call(Hash.REMOVE_IPL, "methtrailer_grp3");
            Function.Call(Hash.REMOVE_IPL, "occl_meth_grp1");
            Function.Call(Hash.REMOVE_IPL, "occl_meth_grp1");
            Function.Call(Hash.REQUEST_IPL, "trailerparkA_grp1");
            Function.Call(Hash.REQUEST_IPL, "occl_trailerA_grp1");
            Function.Call(Hash.REQUEST_IPL, "trailerparkB_grp1");
            Function.Call(Hash.REQUEST_IPL, "occl_trailerB_grp1");
            Function.Call(Hash.REQUEST_IPL, "trailerparkC_grp1");
            Function.Call(Hash.REQUEST_IPL, "occl_trailerC_grp1");
            Function.Call(Hash.REQUEST_IPL, "trailerparkD_grp1");
            Function.Call(Hash.REQUEST_IPL, "occl_trailerD_grp1");
            Function.Call(Hash.REQUEST_IPL, "trailerparkE_grp1");
            Function.Call(Hash.REQUEST_IPL, "occl_trailerE_grp1");
            Function.Call(Hash.REQUEST_IPL, "occl_meth_grp1");
            Function.Call(Hash.REQUEST_IPL, "methtrailer_grp1");
Load Stab city burnt:
            Function.Call(Hash.REMOVE_IPL, "trailerparkA_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkA_grp2");
            Function.Call(Hash.REMOVE_IPL, "occl_trailerA_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkB_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkB_grp2");
            Function.Call(Hash.REMOVE_IPL, "occl_trailerB_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkC_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkC_grp2");
            Function.Call(Hash.REMOVE_IPL, "occl_trailerC_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkD_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkD_grp2");
            Function.Call(Hash.REMOVE_IPL, "occl_trailerD_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkE_grp1");
            Function.Call(Hash.REMOVE_IPL, "trailerparkE_grp2");
            Function.Call(Hash.REMOVE_IPL, "occl_trailerE_grp1");
            Function.Call(Hash.REMOVE_IPL, "des_methtrailer");
            Function.Call(Hash.REMOVE_IPL, "methtrailer_grp1");
            Function.Call(Hash.REMOVE_IPL, "methtrailer_grp2");
            Function.Call(Hash.REMOVE_IPL, "methtrailer_grp3");
            Function.Call(Hash.REMOVE_IPL, "occl_meth_grp1");
            Function.Call(Hash.REMOVE_IPL, "occl_meth_grp1");
            Function.Call(Hash.REQUEST_IPL, "trailerparkA_grp2");
            Function.Call(Hash.REQUEST_IPL, "trailerparkB_grp2");
            Function.Call(Hash.REQUEST_IPL, "trailerparkC_grp2");
            Function.Call(Hash.REQUEST_IPL, "trailerparkD_grp2");
            Function.Call(Hash.REQUEST_IPL, "trailerparkE_grp2");
            Function.Call(Hash.REQUEST_IPL, "des_methtrailer");
            Function.Call(Hash.REQUEST_IPL, "methtrailer_grp3");  //burnt
            //Function.Call(Hash.REQUEST_IPL, "methtrailer_grp2");  //on fire

Load Trevorstrailer:
            Function.Call(Hash.REMOVE_IPL, "TrevorsTrailerTrash");
            Function.Call(Hash.REMOVE_IPL, "TrevorsTrailerTidy");
            Function.Call(Hash.REMOVE_IPL, "TrevorsTrailer");
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 1973.0, 3815.0, 34.0), false);
            Function.Call(Hash.REQUEST_IPL, "TrevorsTrailerTidy");
            Function.Call(Hash._DOOR_CONTROL, 132154435, 1972.769f, 3815.366f, 33.66326f, false, 0.0f, 0.0f, 0.0f);

Load TEQUL-LA_LA:
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -556.5089111328125, 286.318115234375, 81.1763), false);
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -556.5089111328125, 286.318115234375, 81.1763), false);
            Function.Call(Hash.REQUEST_IPL, "v_rockclub");
            Function.Call(Hash._DOOR_CONTROL, 993120320, -565.1712f, 276.6259f, 83.28626f, false, 0.0f, 0.0f, 0.0f);// front door
            Function.Call(Hash._DOOR_CONTROL, 993120320, -561.2866f, 293.5044f, 87.77851f, false, 0.0f, 0.0f, 0.0f);// back door
Unload TEQUL-LA_LA:
            Function.Call(Hash.CAP_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, -556.5089111328125, 286.318115234375, 81.1763), true);
            Function.Call(Hash.REMOVE_IPL, "v_rockclub");
            Function.Call(Hash._DOOR_CONTROL, 993120320, -565.1712f, 276.6259f, 83.28626f, true, 0.0f, 0.0f, 0.0f);// front door
            Function.Call(Hash._DOOR_CONTROL, 993120320, -561.2866f, 293.5044f, 87.77851f, true, 0.0f, 0.0f, 0.0f);// back door

Load Torture
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 147.43299865722656, -2201.370361328125, 3.688), false);
            Function.Call(Hash.REQUEST_IPL, "v_torture");
            Function.Call(Hash._DOOR_CONTROL, 464151082, 134.3954f, -2204.097f, 7.514325f, false, 0.0f, 0.0f, 0.0f);
Unload Torture
            Function.Call(Hash.DISABLE_INTERIOR, Function.Call<int>(Hash.GET_INTERIOR_AT_COORDS, 147.43299865722656, -2201.370361328125, 3.688), false);
            Function.Call(Hash.REMOVE_IPL, "v_torture");
            Function.Call(Hash._DOOR_CONTROL, 464151082, 134.3954f, -2204.097f, 7.514325f, true, 0.0f, 0.0f, 0.0f);

//////////////////////////////////////////////////////////////////////////////////////////////////////////
            Function.Call(Hash._ENABLE_MP_DLC_MAPS, 1);
            Function.Call(Hash._LOAD_MP_DLC_MAPS);

Lost Safe House
            Function.Call(Hash.REMOVE_IPL, "hei_bi_hw1_13_door"); 
            Function.Call(Hash.REQUEST_IPL, "bkr_bi_hw1_13_int"); // coords    984.1552f, -95.3662f, 75.9326f


Yacht
            Function.Call(Hash.REQUEST_IPL, "hei_yacht_heist");
            Function.Call(Hash.REQUEST_IPL, "hei_yacht_heist_Bar");
            Function.Call(Hash.REQUEST_IPL, "hei_yacht_heist_Bedrm");
            Function.Call(Hash.REQUEST_IPL, "hei_yacht_heist_Bridge");
            Function.Call(Hash.REQUEST_IPL, "hei_yacht_heist_DistantLights");
            Function.Call(Hash.REQUEST_IPL, "hei_yacht_heist_enginrm");
            Function.Call(Hash.REQUEST_IPL, "hei_yacht_heist_LODLights");
            Function.Call(Hash.REQUEST_IPL, "hei_yacht_heist_Lounge");

Heist Carrier
            Function.Call(Hash.REQUEST_IPL, "hei_carrier");
            Function.Call(Hash.REQUEST_IPL, "hei_carrier_DistantLights");
            Function.Call(Hash.REQUEST_IPL, "hei_Carrier_int1");
            Function.Call(Hash.REQUEST_IPL, "hei_Carrier_int2");
            Function.Call(Hash.REQUEST_IPL, "hei_Carrier_int3");
            Function.Call(Hash.REQUEST_IPL, "hei_Carrier_int4");
            Function.Call(Hash.REQUEST_IPL, "hei_Carrier_int5");
            Function.Call(Hash.REQUEST_IPL, "hei_Carrier_int6");
            Function.Call(Hash.REQUEST_IPL, "hei_carrier_LODLights");