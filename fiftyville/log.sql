-- Keep a log of any SQL queries you execute as you solve the mystery.
-- The theft took place on Humphrey Street
--
-- SELECT * from crime_scene_reports; => Too much info

--SELECT * from crime_scene_reports WHERE street = "Humphrey Street"; =>
--+-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
--| id  | year | month | day |     street      |                                                                                                       description                                                                                                        |
--+-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
--| 80  | 2021 | 2     | 26  | Humphrey Street | Theft took place at 03:11. Two people witnessed the event.                                                                                                                                                               |
--| 113 | 2021 | 3     | 20  | Humphrey Street | Credit card fraud took place at 08:41. One person witnessed the incident.                                                                                                                                                |
--| 128 | 2021 | 4     | 4   | Humphrey Street | Expired parking meter took place at 03:17. Two people witnessed the event.                                                                                                                                               |
--| 254 | 2021 | 7     | 6   | Humphrey Street | Shoplifting took place at 04:45. Two people witnessed the event.                                                                                                                                                         |
--| 295 | 2021 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
--| 297 | 2021 | 7     | 28  | Humphrey Street | Littering took place at 16:36. No known witnesses.                                                                                                                                                                       |
--| 299 | 2021 | 7     | 30  | Humphrey Street | Littering took place at 17:49. Two people witnessed the event.                                                                                                                                                           |
--+-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
--

--SELECT * from crime_scene_reports WHERE street = "Humphrey Street" and description LIKE "%CS50%"; =>
--+-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
--| id  | year | month | day |     street      |                                                                                                       description                                                                                                        |
--+-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
--| 295 | 2021 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
--+-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

-- SELECT * FROM interviews WHERE transcript LIKE "%bakery%";

--+-----+---------+------+-------+-----+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
--| id  |  name   | year | month | day |                                                                                                                                                     transcript                                                                                                                                                      |
--+-----+---------+------+-------+-----+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
--| 161 | Ruth    | 2021 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
--| 162 | Eugene  | 2021 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
--| 163 | Raymond | 2021 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |
--| 192 | Kiana   | 2021 | 5     | 17  | I saw Richard take a bite out of his pastry at the bakery before his pastry was stolen from him.
--                                                                                                                                                                                             |
--+-----+---------+------+-------+-----+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

-- Time of theft: 28/07/21 at 10:15am
-- The thief used a car parked at the parking lot. Look for cars that left the parking lot around that time.
-- The thief appeared in the ATM on Leggett Street withdrawing money
-- The thief talked to someone for less than a minute, they planned on taking the earliest flight out of Fiftyville on day 29. The accomplice bought the flight tickets for both.

-- SELECT * FROM atm_transactions WHERE year = 2021 AND month = 7 and day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
--+-----+----------------+------+-------+-----+----------------+------------------+--------+
--| id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
--+-----+----------------+------+-------+-----+----------------+------------------+--------+
--| 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
--| 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
--| 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
--| 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
--| 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
--| 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
--| 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
--| 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     |
--+-----+----------------+------+-------+-----+----------------+------------------+--------+

-- Time of theft: 28/07/21 at 10:15am
-- SELECT * FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND activity = "exit" AND minute < 25 AND minute > 15;

--+-----+------+-------+-----+------+--------+----------+---------------+
--| id  | year | month | day | hour | minute | activity | license_plate |
--+-----+------+-------+-----+------+--------+----------+---------------+
--| 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
--| 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
--| 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
--| 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
--| 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
--| 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
--| 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
--| 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
--+-----+------+-------+-----+------+--------+----------+---------------+

SELECT bakery_security_logs.id, license_plate FROM bakery_security_logs
WHERE bakery_security_logs.id IN (
SELECT atm_transactions.id FROM atm_transactions
WHERE year = 2021 AND month = 7 and day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw");

--I'm trying to find an intercetion between ids, but I'm being unable to do so due to syntax errors.

SELECT bakery_security_logs.id FROM bakery_security_logs
WHERE year = 2021 AND month = 7
AND day = 28
AND hour = 10
AND activity = "exit"
AND minute < 25
AND minute > 15
INTERSECT
SELECT atm_transactions.id FROM atm_transactions
WHERE year = 2021 AND month = 7 and day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw";

--
+-----+
| id  |
+-----+
| 264 |
| 266 |
| 267 |
+-----+

--Found the id from people that went to the atm at the suspected time and got out of the bakery at the time of the theft.
-- Those are 264, 266, 267.
--Let's check their names;

SELECT name, id FROM people;
--The people id is not the same from the ones in the other sections...

-- Let's try to FIND the names of suspects.

SELECT bank_accounts.account_number FROM bank_accounts
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
JOIN people ON people.id = bank_accounts.person_id
WHERE bank_accounts.account_number
INTERSECT
SELECT account_number FROM atm_transactions
WHERE atm_transactions.year = 2021 AND atm_transactions.month = 7 and atm_transactions.day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw";


--TRYING TO FIND THE NAME OF SUSPECTS
SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE
atm_transactions.year = 2021 AND atm_transactions.month = 7 and day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";


+---------+
|  name   |
+---------+
| Bruce   |
| Diana   |
| Brooke  |
| Kenny   |
| Iman    |
| Luca    |
| Taylor  |
| Benista |
+---------+


--So, our first suspects are the above. Let's try to find the name of those wich left the bakery
SELECT name FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE
year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND activity = "exit"
AND minute < 25
AND minute > 15;

+---------+
|  name   |
+---------+
| Vanessa |
| Bruce   |
| Barry   |
| Luca    |
| Sofia   |
| Iman    |
| Diana   |
| Kelsey  |
+---------+

-- Now let's try to cross both
SELECT name FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE
year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND activity = "exit"
AND minute < 25
AND minute > 15
INTERSECT
SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE
atm_transactions.year = 2021
AND atm_transactions.month = 7
AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw";

+-------+
| name  |
+-------+
| Bruce |
| Diana |
| Iman  |
| Luca  |
+-------+

--Above are the names of the suspects
SELECT * from people
WHERE name = "Bruce" OR name = "Diana" OR name = "Iman" OR name = "Luca";

+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 396669 | Iman  | (829) 555-5269 | 7049073643      | L93JTIZ       |
| 467400 | Luca  | (389) 555-5198 | 8496433585      | 4328GD8       |
| 514354 | Diana | (770) 555-1861 | 3592750733      | 322W7JE       |
| 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+-------+----------------+-----------------+---------------+

-- Raymond, a witness, said: "As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
-- The thief then asked the person on the other end of the phone to purchase the flight ticket."


-- Let's try to find those calls. Hopefully it will led me to the receiver phone number. The call happened on 7/28/21 around 10:15am and
-- it's duration was less than 60 seconds

SELECT * FROM phone_calls
JOIN people ON people.phone_number = phone_calls.caller
WHERE
year = 2021
AND month = 7
AND day = 28
AND duration < 60;

+-----+----------------+----------------+------+-------+-----+----------+--------+---------+----------------+-----------------+---------------+
| id  |     caller     |    receiver    | year | month | day | duration |   id   |  name   |  phone_number  | passport_number | license_plate |
+-----+----------------+----------------+------+-------+-----+----------+--------+---------+----------------+-----------------+---------------+
| 221 | (130) 555-0289 | (996) 555-8899 | 2021 | 7     | 28  | 51       | 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       |
| 224 | (499) 555-9472 | (892) 555-8872 | 2021 | 7     | 28  | 36       | 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       |
| 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       | 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
| 251 | (499) 555-9472 | (717) 555-1342 | 2021 | 7     | 28  | 50       | 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       |
| 254 | (286) 555-6063 | (676) 555-6554 | 2021 | 7     | 28  | 43       | 449774 | Taylor  | (286) 555-6063 | 1988161715      | 1106N58       |
| 255 | (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49       | 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
| 261 | (031) 555-6622 | (910) 555-3251 | 2021 | 7     | 28  | 38       | 907148 | Carina  | (031) 555-6622 | 9628244268      | Q12B3Z3       |
| 279 | (826) 555-1652 | (066) 555-9701 | 2021 | 7     | 28  | 55       | 395717 | Kenny   | (826) 555-1652 | 9878712108      | 30G67EN       |
| 281 | (338) 555-6650 | (704) 555-2131 | 2021 | 7     | 28  | 54       | 438727 | Benista | (338) 555-6650 | 9586786673      | 8X428L0       |
+-----+----------------+----------------+------+-------+-----+----------+--------+---------+----------------+-----------------+---------------+

--Let's try to cross the names of the suspects and those calls.
SELECT * FROM phone_calls
JOIN people ON people.phone_number = phone_calls.caller
WHERE
year = 2021
AND month = 7
AND day = 28
AND duration < 60
AND (name = "Bruce" OR name = "Diana" OR name = "Iman" OR name = "Luca");

+-----+----------------+----------------+------+-------+-----+----------+--------+-------+----------------+-----------------+---------------+
| id  |     caller     |    receiver    | year | month | day | duration |   id   | name  |  phone_number  | passport_number | license_plate |
+-----+----------------+----------------+------+-------+-----+----------+--------+-------+----------------+-----------------+---------------+
| 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       | 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
| 255 | (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49       | 514354 | Diana | (770) 555-1861 | 3592750733      | 322W7JE       |
+-----+----------------+----------------+------+-------+-----+----------+--------+-------+----------------+-----------------+---------------+

-- Bruce and Diana are the new suspects, but only Bruce got out of the bakery around the time of the theft.

-- So Bruce is the main suspect of the theft. He called (375) 555-8161, let's see the name of the accomplice.

SELECT name FROM people
WHERE phone_number = "(375) 555-8161";

+-------+
| name  |
+-------+
| Robin |
+-------+

-- So, his accomplice is called Robin. Now let's try to find the place they went.
-- Witness said:
-- "I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
-- The thief then asked the person on the other end of the phone to purchase the flight ticket."

-- Let's find the earliest flight out of Fiftyville on the day after the theft.

SELECT
    *
FROM
    flights
WHERE
    year = 2021
AND
    month = 7
AND
    day = 29
ORDER BY
    hour ASC,
    minute ASC;

+----+-------------------+------------------------+------+-------+-----+------+--------+
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+----+-------------------+------------------------+------+-------+-----+------+--------+
| 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
| 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     |
| 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
| 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
| 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
+----+-------------------+------------------------+------+-------+-----+------+--------+

--Let's see if origin_airport_id = 8 is Fiftyville

SELECT
    *
FROM
    airports
WHERE
    id = 8;

+----+--------------+-----------------------------+------------+
| id | abbreviation |          full_name          |    city    |
+----+--------------+-----------------------------+------------+
| 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
+----+--------------+-----------------------------+------------+

--It's fiftyville
--Let's check the destination of the earliest flight

SELECT
    *
FROM
    airports
WHERE
    id = 4;

+----+--------------+-------------------+---------------+
| id | abbreviation |     full_name     |     city      |
+----+--------------+-------------------+---------------+
| 4  | LGA          | LaGuardia Airport | New York City |
+----+--------------+-------------------+---------------+

--My guess is that Bruce and Robin stole the duck and went to NY.

--THAT'S RIGHT! WE GOT THEM! OUR DUCK IS SAFELY BACK.