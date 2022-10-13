# Import Libraries
import requests
import json
import datetime

# Define Parameters Dictionary
params = dict()
params['access_token'] = 'XXXXXXXXXXXXXXXXXXX'        # not an actual access token
params['client_id'] = '111111111111'                  # not an actual client id
params['client_secret'] = '000000000XXXXXXXXXXXX'     # not an actual client secret
params['graph_domain'] = 'https://graph.facebook.com'
params['graph_version'] = 'v12.0'
params['endpoint_base'] = params['graph_domain'] + '/' + params['graph_version'] + '/'
params['page_id'] = '22222222222222'                  # not an actual page id
params['instagram_account_id'] = '33333333333'        # not an actual instagram business account id
params['ig_username'] = 'galihputrala'

# Define Endpoint Parameters
endpointParams = dict()
endpointParams['input_token'] = params['access_token']
endpointParams['access_token'] = params['access_token']

# Define URL
url = params['graph_domain'] + '/debug_token'

# Requests Data
data = requests.get(url, endpointParams)
access_token_data = json.loads(data.content)

print("Token Expires: ", datetime.datetime.fromtimestamp(access_token_data['data']['expires_at']))

# Define URL
url = params['endpoint_base'] + 'oauth/access_token'

# Define Endpoint Parameters
endpointParams = dict() 
endpointParams['grant_type'] = 'fb_exchange_token'
endpointParams['client_id'] = params['client_id']
endpointParams['client_secret'] = params['client_secret']
endpointParams['fb_exchange_token'] = params['access_token']

# Requests Data
data = requests.get(url, endpointParams )
long_lived_token = json.loads(data.content)
long_lived_token

# Basic Insights 

# Define URL
url = params['endpoint_base'] + params['instagram_account_id'] + '/media'

# Define Endpoint Parameters
endpointParams = dict()
endpointParams['fields'] = 'id,caption,media_type,media_url,permalink,thumbnail_url,timestamp,username,like_count,comments_count'
endpointParams['access_token'] = params['access_token']

# Requests Data
data = requests.get(url, endpointParams )
basic_insight = json.loads(data.content)
basic_insight
