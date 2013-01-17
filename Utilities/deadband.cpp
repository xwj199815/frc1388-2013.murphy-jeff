
// create a deadband for joysticks
// return value is the modified/deadbanded version of the input
// db is the deadband value (distance from 0), in the range [0,1]

float deadband(float input, float db=0.1) {
	float output = 0;	// default value
	// error check (shouldn't ever get here):
	if (db == 1) { db = 9999; }	// some huge value that input should not reach
	
	// input is assumed to be in the range [-1,1]
	if (input > db) {
		output = (input-db)/(1-db); 
	} else 	if (input < (-db)) {
		output = (input+db)/(1-db); 
	} // else we're in the deadband region
	
	return output;
}
