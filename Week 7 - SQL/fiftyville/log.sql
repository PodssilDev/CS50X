-- Keep a log of any SQL queries you execute as you solve the mystery.
--- QUERY NUMBER 1 ---
--- Check the description of the crime report ---
SELECT description
FROM crime_scene_reports
WHERE month = 7
AND year = 2023
AND day = 28;

--- QUERY NUMBER 2 ---
--- Check the interviews related to the crime report ---
SELECT *
FROM interviews
WHERE day = 28
AND month = 7
AND year = 2023;

--- QUERY NUMBER 3 ---
--- Check the Bakery Security Logs with data from Interviews ---
SELECT *
FROM bakery_security_logs
WHERE day = 28
AND month = 7
AND year = 2023
AND hour = 10
AND minute BETWEEN 15 AND 25;

--- QUERY NUMBER 4 ---
--- Associate License Plate to a Person ---
SELECT people.name, bakery_security_logs.license_plate, bakery_security_logs.minute
FROM bakery_security_logs
JOIN people ON people.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.day = 28
AND bakery_security_logs.month = 7
AND bakery_security_logs.year = 2023
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute BETWEEN 15 AND 25;

--- QUERY NUMBER 5 ---
--- Check ATM information ---
SELECT people.name, atm_transactions.account_number, atm_transactions.amount
FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON people.id = bank_accounts.person_id
WHERE atm_transactions.atm_location = "Leggett Street"
AND atm_transactions.day = 28
AND atm_transactions.month = 7
AND atm_transactions.year = 2023
AND atm_transactions.transaction_type = "withdraw";

--- QUERY NUMBER 6 ---
--- Check Phone Calls information
SELECT people.name, phone_calls.caller, phone_calls.receiver, phone_calls.duration
FROM phone_calls
JOIN people ON people.phone_number = phone_calls.caller
WHERE phone_calls.year = 2023
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration < 60;

--- QUERY NUMBER 7 ---
--- Find Fiftyville Airport ID ---
SELECT *
FROM airports
WHERE city = "Fiftyville";

--- QUERY NUMBER 8 ---
--- Check flights that left Fiftyville ---
SELECT flights.id, airports.full_name, flights.hour, flights.minute
FROM flights
JOIN airports ON flights.destination_airport_id = airports.id
WHERE origin_airport_id = 8
AND day = 29
AND month = 7
AND year = 2023
ORDER BY flights.hour , flights.minute;

--- QUERY NUMBER 9 ---
--- Combine information obtained ---
SELECT people.name
FROM bakery_security_logs
JOIN people ON people.license_plate = bakery_security_logs.license_plate
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE bakery_security_logs.day = 28
AND bakery_security_logs.month = 7
AND bakery_security_logs.year = 2023
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute BETWEEN 15 AND 25
AND atm_transactions.atm_location = "Leggett Street"
AND atm_transactions.day = 28
AND atm_transactions.month = 7
AND atm_transactions.year = 2023
AND atm_transactions.transaction_type = "withdraw"
AND phone_calls.year = 2023
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration < 60;

--- QUERY NUMBER 10 ---
--- Find out who the thief is between Bruce and Diana ---
SELECT people.name
FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE passengers.flight_id = 36;

--- QUERY NUMBER 11 ---
--- Find out the lists of possible accomplices ---
SELECT *
FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE phone_calls.year = 2023
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration < 60;

--- QUERY NUMBER 12 ---
--- Find Bruce's Cellphone ---
SELECT phone_number
FROM people
WHERE name = "Bruce";

--- QUERY NUMBER 13 ---
--- Find the Accomplice ---
SELECT people.name
FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE phone_calls.year = 2023
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration < 60
AND phone_calls.caller = "(367) 555-5533";

--- Thus, Bruce is the thief. Bruce escaped to LaGuardia Airport (New York) and his accomplice was Robin. ---
