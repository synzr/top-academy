#/bin/bash

USER_AGENT='Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:135.0) Gecko/20100101 Firefox/135.0'
ORIGIN='https://journal.top-academy.ru'

# NOTE: ключ приложения из дневника учащегося
APPLICATION_KEY='6a56a5df2667e65aab73ce76d1dd737f7d1faef9c52e8b8c55ac75f565d8e8a6'

REQUEST_BODY=$(
cat << EOF
{
    "application_key": "$APPLICATION_KEY",
    "id_city": null,
    "password": "$CREDENTIALS_PASSWORD",
    "username": "$CREDENTIALS_USERNAME"
}
EOF
)

curl -v \
  -X POST \
  -H "User-Agent: $USER_AGENT" \
  -H "Accept: application/json" \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer null" \
  -H "Origin: $ORIGIN" \
  -H "Referer: $ORIGIN/" \
  -d "$REQUEST_BODY" \
  https://msapi.top-academy.ru/api/v2/auth/login | jq .access_token
