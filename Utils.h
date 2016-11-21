/*
		File: Utils.h
    Created on: 20/11/2016
    Author: Felix de las Pozas Alvarez

		This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef UTILS_H_
#define UTILS_H_

// C++
#include <time.h>

// Qt
#include <QString>

enum class Temperature: char { CELSIUS = 0, FAHRENHEIT };

/** \struct Configuration
 *
 */
struct Configuration
{
    double latitude;         /** location latitude in degrees.  */
    double longitude;        /** location longitude in degrees. */
    QString country;         /** location's country.            */
    QString region;          /** location's region.             */
    QString city;            /** location's city.               */
    QString zipcode;         /** location's zip code.           */
    QString isp;             /** internet service provider.     */
    QString ip;              /** internet address.              */
    QString timezone;        /** location's timezone.           */
    QString owm_apikey;      /** OpenWeatherMap API Key.        */
    Temperature units;       /** temperature units.             */
    unsigned int updateTime; /** time between updates.  */

    bool isValid() const
    {
      return (latitude <= 90.0) &&   (latitude >= -90.0) &&
             (longitude <= 180.0) && (longitude >= -180) &&
             !owm_apikey.isEmpty();
    }
};

/** \brief Converts the given temp to the given units and returns the value.
 * \param[in] temp temperature in Kelvin.
 * \param[in] units units to convert to.
 *
 */
const double convertKelvinTo(const double temp, const Temperature units);

/** \brief Converts the given unix timestamp to a struct tm and returns it.
 * \param[in] timestamp unix timestamp.
 *
 */
const struct tm* unixTimeStampToDate(const long long timestamp);

#endif // UTILS_H_
