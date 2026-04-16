// Legacy API Fetcher

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Scanner;

class WeatherAPIClient {
    public double getTemperatureInFahrenheit(double x, double y) {
        try {
            String apiUrl = "https://api.weather.gov/points/" + x + "," + y;
            String response = fetchAPI(apiUrl);

            if (response == null) {
                // System.out.println("response");

                return -1; // Error case
            }

            // Extract forecast URL manually using substring and indexOf
            String forecastUrl = extractValue(response, "\"forecastHourly\": \"", "\"");

            if (forecastUrl == null) {
                // System.out.println("forecastUrl " + forecastUrl);

                return -1; // Error case
            }

            // Fetch forecast data
            String forecastResponse = fetchAPI(forecastUrl);
            String tempFString = extractValue(forecastResponse, "\"temperature\":", ",");

            if (tempFString == null) {
                return -1; // Error case
            }

            return Double.parseDouble(tempFString);
        } catch (Exception e) {
            // System.out.println("Exception");
            return -1; // Handle API fetch error
        }
    }

    public double getHumidity(double x, double y) {
        try {
            String apiUrl = "https://api.weather.gov/points/" + x + "," + y;
            String response = fetchAPI(apiUrl);

            // Extract forecast URL manually
            String forecastUrl = extractValue(response, "\"forecastHourly\":\"", "\"");

            if (forecastUrl == null) {
                // System.out.println("forecast URL Error");
                return -1; // Error case
            }

            // Fetch forecast data
            String forecastResponse = fetchAPI(forecastUrl);
            String humidityString = extractValue(forecastResponse, "\"relativeHumidity\":", ",");

            if (humidityString == null) {
                // System.out.println("humidityString Error");
                return -1; // Error case
            }

            return Double.parseDouble(humidityString);
        } catch (Exception e) {
            return -1; // Handle API fetch error
        }
    }

    private String fetchAPI(String apiUrl) throws Exception {
        URL url = new URL(apiUrl);
        HttpURLConnection conn = (HttpURLConnection) url.openConnection();
        conn.setRequestMethod("GET");
        conn.setRequestProperty("User-Agent", "Mozilla/5.0 Chrome/4.0.249.0");

        BufferedReader reader = new BufferedReader(new InputStreamReader(conn.getInputStream()));
        StringBuilder response = new StringBuilder();
        String line;
        while ((line = reader.readLine()) != null) {
            response.append(line);
        }
        reader.close();

        return response.toString();
    }

    private String extractValue(String json, String startKey, String endKey) {
        int startIndex = json.indexOf(startKey);
        // System.out.println(startIndex +  " == startIndex");
        if (startIndex == -1) return null;
        startIndex += startKey.length();
        int endIndex = json.indexOf(endKey, startIndex);
        if (endIndex == -1) return null;
        return json.substring(startIndex, endIndex).trim();
    }
}
    // public static void main(String[] args) {
    //     // test the legacy api
    //     // create an instance of the API client
    //     WeatherAPIClient client = new WeatherAPIClient();

    //     double latitude = 40.7128;
    //     double longitude = -74.0060;

    //     double tempf = client.getTemperatureInFahrenheit(latitude, longitude);
    //     double humidity = client.getHumidity(latitude, longitude);

    //     System.out.println("Temp in f == " + tempf);
    //     System.out.println("Humidity == " + humidity + "%");
    // }


// 1. make an interface
interface WeatherService {
    double getTemperatureInCelsius(double x, double y);
    double getHumidity(double x, double y);
}

// 2. adapder
// Call the existing WeatherAPIClient
// Convert Fahrenheit → Celsius
// Return:
// Temperature (in Celsius)
// Humidity %

// CELCIUS  = (5/9) * (F - 32)

class WeatherAdapter implements WeatherService {

    // initialise a weatherAPIClient instance
    private WeatherAPIClient client;

    // constructor
    public WeatherAdapter() {
        this.client = new WeatherAPIClient();
    }

    public WeatherAdapter(WeatherAPIClient client) {
        this.client = client;
    }

    // now override what is written insire the weatherAPIClient
    // We need the same input that weatherAPI getTemp needs x, y
    @Override
    public double getTemperatureInCelsius(double x, double y) {
        try {
            String apiUrl = "https://api.weather.gov/points/" + x + "," + y;
            String response = fetchAPI(apiUrl);

            if (response == null) {
                // System.out.println("response");
                return -1; // Error case
            }

            // Extract forecast URL manually using substring and indexOf
            String forecastUrl = extractValue(response, "\"forecastHourly\": \"", "\"");

            if (forecastUrl == null) {
                // System.out.println("forecastUrl " + forecastUrl);
                return -1; // Error case
            }

            // Fetch forecast data
            String forecastResponse = fetchAPI(forecastUrl);
            String tempFString = extractValue(forecastResponse, "\"temperature\": ", ",");

            if (tempFString == null) {
                return -1; // Error case
            }

            // the weatherAPI already returns fahrenheit, so we just need to convert that
            double tempf = Double.parseDouble(tempFString);
            // CELCIUS  = (5/9) * (F - 32)

            return ((tempf - 32) * 5)/9;
        } catch (Exception e) {
            // System.out.println("Exception");
            return -1; // Handle API fetch error
        }       
    }

    @Override
    public double getHumidity(double x, double y) {
        try {
            String apiUrl = "https://api.weather.gov/points/" + x + "," + y;
            String response = fetchAPI(apiUrl);

            // Extract forecast URL manually
            String forecastUrl = extractValue(response, "\"forecastHourly\": \"", "\"");

            if (forecastUrl == null) {
                System.out.println("forecast URL Error");
                return -1; // Error case
            }

            // Fetch forecast data
            String forecastResponse = fetchAPI(forecastUrl);
            // now lets' find the value to humidity
            int startIndex = forecastResponse.indexOf("\"relativeHumidity\":");
            if (startIndex == -1) return -1;

            // now find the substring value after this point
            String sub = forecastResponse.substring(startIndex);
            // System.out.println("substring" + sub);
            // finally get the string after value
            String humidityString = extractValue(sub, "\"value\": ", "}");
            // System.out.println("humidityString" + humidityString + "surrounded");
            // humidityString
            if (humidityString == null) {
                System.out.println("humidityString Error");
                return -1; // Error case
            }

            return Double.parseDouble(humidityString);
        } catch (Exception e) {
            return -1; // Handle API fetch error
        }
    }


    private String fetchAPI(String apiUrl) throws Exception {
        URL url = new URL(apiUrl);
        HttpURLConnection conn = (HttpURLConnection) url.openConnection();
        conn.setRequestMethod("GET");
        conn.setRequestProperty("User-Agent", "Mozilla/5.0 Chrome/4.0.249.0");

        BufferedReader reader = new BufferedReader(new InputStreamReader(conn.getInputStream()));
        StringBuilder response = new StringBuilder();
        String line;
        while ((line = reader.readLine()) != null) {
            response.append(line);
        }
        reader.close();

        return response.toString();
    }

    private String extractValue(String json, String startKey, String endKey) {
        int startIndex = json.indexOf(startKey);
        // System.out.println(startIndex +  " == startIndex");
        if (startIndex == -1) return null;
        startIndex += startKey.length();
        int endIndex = json.indexOf(endKey, startIndex);
        if (endIndex == -1) return null;
        return json.substring(startIndex, endIndex).trim();
    } 
}

public class WeatherApp {
    public static void main(String[] args) {

            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter latitude (x): ");
            double x = scanner.nextDouble();
            System.out.print("Enter longitude (y): ");
            double y = scanner.nextDouble();
            scanner.close();

            WeatherAPIClient apiClient = new WeatherAPIClient();
            WeatherService weatherService = new WeatherAdapter(apiClient);

            // TODO: Fetch and print temperature in Celsius
            // TODO: Fetch and print humidity


            double tempC = weatherService.getTemperatureInCelsius(x, y);
            double humidity = weatherService.getHumidity(x, y);

            System.out.printf("Temperature: %.1f°C\n", tempC);
            System.out.println("Humidity: " + (int)humidity + "%");
    }
}

// public class Main {
//     public static void main(String[] args) {
//         // fahrenheit

//         // test the legacy api
//         // create an instance of the API client
//         WeatherAPIClient client = new WeatherAPIClient();

//         // double latitudeF = 40.7128;
//         // double longitudeF = -74.0060;

//         double latitude2 = 38.8977;
//         double longitude2 = -77.0365;       

//         double tempf = client.getTemperatureInFahrenheit(latitude2, longitude2);
//         double humidityF = client.getHumidity(latitude2, longitude2);

//         System.out.println("tempf: " + tempf);
//         System.out.println("Humidity == " + humidityF + "%");

//         // celsius

//         WeatherService weather = new WeatherAdapter();

//         double latitude = 38.8977;
//         double longitude = -77.0365;

//         double tempC = weather.getTemperatureInCelsius(latitude, longitude);
//         double humidity = weather.getHumidity(latitude, longitude);

//         // tester
//         double test = ((45 - 32) * 5)/9;
//         // System.out.println("What is the math: " + test);
//         System.out.println(tempC);
//         System.out.println("Humidity == " + humidity + "%");

//     }    
// }
// 38.8977
// -77.0365

