ATEMdemo:


	store parameters
	
	check if interrupt mode is selected
	
	set thread affinity
	
	create motification context
	
	/*
	*	demo code: remove/change this in your applicatuon
	*	initialize application
	*/
		myAppInit();
	
	start ras server if enabled
	
	initialize EtherCAT master
	
	create cyclic process data Thread
		S_pvtJobThread = OsCreateThread( etcJobTask )
	
	waiting until Thread is running
	
	configure master
	
	configure DC/DCM master is started with ENI
		config DC
		config DCM
	register client
		ecatRegisterClient(ecatNotifyCallback, ***);
	
	print found slaves
	
	print MAC address

	Start EtherCAT BUS --> set master state to OPERATIONAL if ENI file provided
		start master and bus state to INIT
	
	/*
	*	demo code: remove/change this in your applicatuon
	*	search for some well know slaves
	*/
		myAppPrepare();
	set master and bus state to proOP
	
	skip this step if demo started without ENI
	
		/*	
		*	demo code: remove/change this in your applicatuon
		*	setup the found slaves
		*	after reaching the proOP state CANopen SDO uploads
		*	and downloads are possible
		*/
			myAppSetup();
		set master and bus state to safeOP
		
		set master and bus state to OP
		
	enabling mode switch warning for shadowed task
		
	run the demo
		while()
		{	
			myAppDiagnosis();
		}
		
	EXIT:
		stop EtherCAT BUS --> set master state to INIT
		
		unregister client
		
		shutdown tEcJobTask
		
		deinitialize master
		
		stop RAS server
		
		
		
	
	
		
		
		------------------
thread:		
		etcJobTask(){
			myAppWorkpd();
		}
		
		
	ecatNotifyCallback() {
		myAppNOtify();
	}
		
		
		
		
		
		
		
	