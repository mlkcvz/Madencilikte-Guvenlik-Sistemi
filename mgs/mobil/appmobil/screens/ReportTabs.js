import React from 'react'
import { StyleSheet, Text, View } from 'react-native'
import { NavigationContainer } from '@react-navigation/native';
import * as firebase from "firebase";

import { createBottomNavigator, createBottomTabNavigator } from '@react-navigation/bottom-tabs'

import Reports from './Reports'
import WeeklyReport from './WeeklyReport'
import MonthlyReport from './MonthlyReport'
import AnnualReport from './AnnualReport'
export default class ReportTabs extends React.Component {
   
   

componentDidMount = () => {
   
}
render(){
    const Tabs = createBottomTabNavigator()
    return (
        <Tabs.Navigator>
            <Tabs.Screen name="Reports" component={Reports} />
            <Tabs.Screen name="WeeklyReport" component={WeeklyReport} />
            <Tabs.Screen name="MonthlyReport" component={MonthlyReport} />
            <Tabs.Screen name="AnnualReport" component={AnnualReport} />
        </Tabs.Navigator>
    )
}
}

