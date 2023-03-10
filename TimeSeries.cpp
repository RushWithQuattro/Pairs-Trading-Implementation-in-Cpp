// #include "TimeSeries.h"

// // Constructor (read from CSV file)
// TimeSeries::TimeSeries(std::string name, std::string filepath)
// {
// 	std::ifstream file(filepath);
// 	std::string line = "";
// 	std::string datetime = "";
// 	double price = 0.0;
// 	DataPoint* dp;
// 	struct tm tm = {0};
// 	int year = 0;
// 	int month = 0;
// 	int day = 0;
// 	int hour = 0;
// 	int minute = 0;

// 	this->name = name;
// 	this->sample_datetime = "";
// 	this->sample_timestamp = 0;

// 	if(!file.is_open())
// 	{
// 		return;
// 	}

// 	// Skip CSV header
// 	// getline(file, line);
// 	getline(file, line);

// 	// Read first line of relevant data
// 	getline(file, line);

// 	while(line.size() != 0)
// 	{
// 		datetime = line.substr(0, 16);                             // get date
// 		price = std::stod(line.substr(20, line.size() - 20));  // get value
// 		dp = new DataPoint(datetime, price);                       // create new DataPoint object

// 		sscanf(datetime.c_str(), "%d-%d-%d-%d-%d", &year, &month, &day, &hour, &minute); // convert date to time stamp
// 		tm.tm_year = year - 1900;
// 		tm.tm_mon = month - 1;
// 		tm.tm_mday = day;
// 		tm.tm_hour = hour;
// 		tm.tm_min = minute;
// 		this->series.insert(std::pair<time_t, DataPoint*>(mktime(&tm), dp));

// 		// Read next line of relevant data
// 		getline(file, line);
// 	}

// 	return;
// }

// // Constructor
// TimeSeries::TimeSeries(std::string name)
// {
// 	this->name = name;
// 	this->sample_datetime = "";
// 	this->sample_timestamp = 0;

// 	return;
// }

// // Destructor
// TimeSeries::~TimeSeries()
// {
// 	// Delete all data points in the time series
// 	for(iterator it = this->series_begin(); it != this->series_end(); ++it)
// 	{
// 		delete (*it).second;
// 	}

// 	series.clear();

// 	return;
// }

// // Insert new elements in the time series
// bool TimeSeries::insert(std::string datetime, double price)
// {
// 	DataPoint* dp;
// 	struct tm tm = {0};
// 	int year = 0;
// 	int month = 0;
// 	int day = 0;
// 	int hour = 0;
// 	int minute = 0;
// 	time_t timestamp;

// 	sscanf(datetime.c_str(), "%d-%d-%d-%d-%d", &year, &month, &day, &hour, &minute); // convert date to time stamp
// 	tm.tm_year = year - 1900;
// 	tm.tm_mon = month - 1;
// 	tm.tm_mday = day;
// 	tm.tm_hour = hour;
// 	tm.tm_min = minute;
// 	timestamp = mktime(&tm);

// 	// Check if there is already a value for the desired
// 	// date in the time series, then add if negative
// 	if(this->series.count(timestamp) == 0)
// 	{
// 		dp = new DataPoint(datetime, price);
// 		this->series.insert(std::pair<time_t, DataPoint*>(timestamp, dp));

// 		return true;
// 	}
// 	else
// 	{
// 		return false;
// 	}
// }

// // Setter for the in-sample period end date
// void TimeSeries::set_sample_date(/*std::string*/time_t sample_datetime)
// {
// 	// struct tm tm = {0};
// 	// int year = 0;
// 	// int month = 0;
// 	// int day = 0;
// 	// int hour = 0;
// 	// int minute = 0;

// 	// this->sample_datetime = sample_datetime;

// 	// sscanf(this->sample_datetime.c_str(), "%d-%d-%d-%d-%d", &year, &month, &day, &hour, &minute); // convert date to time stamp
// 	// tm.tm_year = year - 1900;
// 	// tm.tm_mon = month - 1;
// 	// tm.tm_mday = day;
// 	// tm.tm_hour = hour;
// 	// tm.tm_min = minute;
// 	// this->sample_timestamp = mktime(&tm);
//     this->sample_timestamp = sample_datetime;
// 	return;
// }

// // Remove the in/out-of-sample boundary
// // void TimeSeries::reset_sample_date()
// // {
// // 	this->sample_datetime = "";
// // 	this->sample_timestamp = 0;

// // 	return;
// // }

// // Getter for the name of the time series
// std::string TimeSeries::get_name()
// {
// 	return this->name;
// }

// // Getter for the in-sample period end date
// std::string TimeSeries::get_sample_date()
// {
// 	return this->sample_datetime;
// }

// // Getter for the in-sample period end time stamp
// time_t TimeSeries::get_sample_timestamp()
// {
// 	return this->sample_timestamp;
// }

// // Time series length
// int TimeSeries::series_size()
// {
// 	return this->series.size();
// }

// // In-sample series length
// int TimeSeries::sample_size()
// {
// 	if(this->get_sample_timestamp() != 0)
// 	{
// 		return std::distance(this->series.begin(), this->series.lower_bound(this->sample_timestamp)) + 1;
// 	}
// 	else
// 	{
// 		return this->series.size();
// 	}
// }

// // Iterator to the begin of the time series
// TimeSeries::iterator TimeSeries::series_begin()
// {
// 	return this->series.begin();
// }

// // Iterator to the end of the time series
// TimeSeries::iterator TimeSeries::series_end()
// {
// 	return this->series.end();
// }

// // Reverse iterator to the end of the time series
// TimeSeries::reverse_iterator TimeSeries::series_rbegin()
// {
// 	return this->series.rbegin();
// }

// // Reverse iterator to the begin of the time series
// TimeSeries::reverse_iterator TimeSeries::series_rend()
// {
// 	return this->series.rend();
// }

// // Iterator to the begin of the in-sample series
// TimeSeries::iterator TimeSeries::in_sample_begin()
// {
// 	return this->series.begin();
// }

// // Iterator to the end of the in-sample series
// TimeSeries::iterator TimeSeries::in_sample_end()
// {
// 	if(this->get_sample_timestamp() != 0)
// 	{
// 		return ++this->series.lower_bound(this->sample_timestamp);
// 	}
// 	else
// 	{
// 		return this->series.end();
// 	}
// }

// // Reverse iterator to the end of the in-sample series
// TimeSeries::reverse_iterator TimeSeries::in_sample_rbegin()
// {
// 	if(this->get_sample_timestamp() != 0)
// 	{
// 		return TimeSeries::reverse_iterator(this->series.lower_bound(this->sample_timestamp));
// 	}
// 	else
// 	{
// 		return this->series.rbegin();
// 	}
// }

// // Reverse iterator to the begin of the in-sample series
// TimeSeries::reverse_iterator TimeSeries::in_sample_rend()
// {
// 	return this->series.rend();
// }

// // Iterator to the begin of the out-of-sample series
// // TimeSeries::iterator TimeSeries::out_sample_begin()
// // {
// // 	if(this->get_sample_timestamp() != 0)
// // 	{
// // 		return ++this->series.lower_bound(this->sample_timestamp);
// // 	}
// // 	else
// // 	{
// // 		return this->series.begin();
// // 	}
// // }

// // Iterator to the end of the out-of-sample series
// // TimeSeries::iterator TimeSeries::out_sample_end()
// // {
// // 	return this->series.end();
// // }

// // Reverse iterator to the end of the out-of-sample series
// // TimeSeries::reverse_iterator TimeSeries::out_sample_rbegin()
// // {
// // 	return this->series.rbegin();
// // }

// // Reverse iterator to the begin of the out-of-sample series
// // TimeSeries::reverse_iterator TimeSeries::out_sample_rend()
// // {
// // 	if(this->get_sample_timestamp() != 0)
// // 	{
// // 		return TimeSeries::reverse_iterator(this->series.lower_bound(this->sample_timestamp));
// // 	}
// // 	else
// // 	{
// // 		return this->series.rend();
// // 	}
// // }
